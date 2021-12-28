#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#define DATA_BUFFER 1024 //默认缓冲区大小
int main(int argc, char * argv[])
{
WSADATA wsaData;
SOCKET sClient;
int iPort = 5050;
int iLen;//从服务器端接收的数据长度
char buf[DATA_BUFFER];//接收数据的缓冲区
struct sockaddr_in ser;//服务器端地址
//判断参数输入是否正确：client [Server IP]
if(argc<2)
{
//提示在命令行中输入服务器 IP 地址
printf("Usage: client [server IP address]\n");
return -1;
}
memset(buf,0,sizeof(buf));//接收缓冲区初始化
if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
{
printf("Failed to load Winsock.\n");
return -1;

}
//填写要连接的服务器地址信息
ser.sin_family = AF_INET;
ser.sin_port = htons(iPort);
//inet_addr()将命令行中输入的点分 IP 地址转换为二进制表示的网络字节序 IP 地址
ser.sin_addr.s_addr = inet_addr(argv[1]);
//建立客户端流式套接口
sClient = socket(AF_INET,SOCK_STREAM,0);
if(sClient == INVALID_SOCKET)
{
printf("socket() Failed: %d\n",WSAGetLastError());
return -1;
}
//请求与服务器端建立 TCP 连接
if(connect(sClient,(struct sockaddr *)&ser,sizeof(ser)) == INVALID_SOCKET)
{
printf("connect() Failed: %d\n",WSAGetLastError());
return -1;
}
else
{
//从服务器端接收数据
iLen = recv(sClient,buf,sizeof(buf),0);
if(iLen == 0)
return -1;
else if(iLen == SOCKET_ERROR)
{
printf("recv() Failed: %d\n",WSAGetLastError());
return -1;
}
else
printf("recv() data from server: %s\n",buf);
}
closesocket(sClient);
WSACleanup();
return 0;
}
