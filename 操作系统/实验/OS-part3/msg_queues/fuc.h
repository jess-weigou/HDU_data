#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <pthread.h>
 
#define MAX_TEXT_SIZE 512
#define KEY 1100
 
typedef struct my_msg_buffer
{
    long int type; //1琛ㄧずsend1锛?琛ㄧずsend2锛?琛ㄧずreceive1锛?琛ㄧずreceive2
    char text[MAX_TEXT_SIZE];
} message;
 
 
int get_semaphore_value(sem_t *t)
{
    int value = -1;
    sem_getvalue(t, &value);
    return value;
}
 
int my_msgsnd(int msgid, message *msg, char *location)
{
    printf("--------------------------------------------\n");
    printf("in my_msgsnd,location is %s\n", location);
    printf("message is %s\n\n", msg->text);
 
/*
            msgsnd函数 
			向消息队列发送消息的函数
			第一个参数是消息队列的标识符 
			第二个参数是要发送消息的地址
			第三个参数是要发送的消息的长度（字节数） 
			第四个参数是 0表示忽视标志位 
			*/ 
    if (msgsnd(msgid, (void *)msg, MAX_TEXT_SIZE, 0) < 0)
    {
        printf("in %s,msgsnd failed!\n", location);
        return -1;
    }
    return 0;
}
 
int my_msgrcv(int msgid, message *msg, char *location, long type)
{
    printf("--------------------------------------------\n");
    printf("in my_msgrcv,location is %s\n", location);
    printf("message is %s\n", msg->text);
    printf("rcv type is %ld\n\n", type);
 
//取消息函数，从msgid消息队列中取到msg中，并且大小为第三个参数，只取第一个出现的type类型的消息 
    if (msgrcv(msgid, (void *)msg, MAX_TEXT_SIZE, type, 0) < 0)
    {
        printf("in %s,msgrcv failed!\n", location);
        return -1;
    }
    return 0;
}