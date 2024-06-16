#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_PORT 5050 //服务端默认端口
int main(int argc, char* argv[])
{
int iPort = DEFAULT_PORT;
WSADATA wsaData;
SOCKET sListen,sAccept;
int iLen; //客户地址长度
int iSend;//发送数据长度
char buf[] = "I am a server";//要发送给客户的信息
struct sockaddr_in ser,cli;//服务器和客户的地址
if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
{
printf("Failed to load Winsock.\n");
return -1;
}

sListen = socket(AF_INET,SOCK_STREAM,0);//创建服务器端套接口
if(sListen == INVALID_SOCKET)
{
printf("socket() Failed: %d\n",WSAGetLastError());
return -1;
}
//以下建立服务器端地址
//使用 IP 地址族
ser.sin_family = AF_INET;
//使用 htons()把双字节主机序端口号转换为网络字节序端口号
ser.sin_port = htons(iPort);
//htonl()把一个四字节主机序 IP 地址转换为网络字节序主机地址
//使用系统指定的 IP 地址 INADDR_ANY
ser.sin_addr.s_addr = htonl(INADDR_ANY);
//bind()函数进行套接定与地址的绑定
if(bind(sListen,(LPSOCKADDR)&ser,sizeof(ser)) == SOCKET_ERROR)
{
printf("bind() Failed: %d\n",WSAGetLastError());
return -1;
}
//进入监听状态
if(listen(sListen,5) == SOCKET_ERROR)
{
printf("lisiten() Failed: %d\n",WSAGetLastError());
return -1;
}
//初始化客户地址长度参数
iLen = sizeof(cli);
//进入一个无限循环，等待客户的连接请求
while(1)
{
sAccept = accept(sListen,(struct sockaddr *)&cli,&iLen);
if(sAccept == INVALID_SOCKET)
{
printf("accept() Failed: %d\n",WSAGetLastError());
return -1;
}
//输出客户 IP 地址和端口号
printf("Accepted client IP:[%s],port:[%d]\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
//给连接的客户发送信息
iSend = send(sAccept,buf,sizeof(buf),0);
if(iSend == SOCKET_ERROR)
{
printf("send() Failed: %d\n",WSAGetLastError());

break;
}
else if(iSend == 0)
{
break;
}
else
{
printf("send() byte: %d\n",iSend);
}
closesocket(sAccept);
}
closesocket(sListen);
WSACleanup();
return 0;
}
