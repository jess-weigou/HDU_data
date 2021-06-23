#include "fuc.h"
 
int run_sender1()
{
 
    // sem_unlink("reply_over31");
    // sem_unlink("reply_over41");
    // sem_unlink("reply_over32");
    // sem_unlink("reply_over42");
 
    int msgid;
    int close1 = 0;
    int close2 = 0;
    int close = 0;
    message msg;
    int choice;
    int semvalue;
 
    sem_t *reply_over31;
    sem_t *reply_over41;
    sem_t *reply_over32;
    sem_t *reply_over42;
 
    reply_over31 = sem_open("reply_over31", O_CREAT | O_RDWR, 0666, 0);
    reply_over41 = sem_open("reply_over41", O_CREAT | O_RDWR, 0666, 0);
    reply_over32 = sem_open("reply_over32", O_CREAT | O_RDWR, 0666, 0);
    reply_over42 = sem_open("reply_over42", O_CREAT | O_RDWR, 0666, 0);
 
    msgid = msgget((key_t)KEY, 0666 | IPC_CREAT);
    //创建消息队列 
    if (msgid == -1)
    {
        printf("msgget failed!\n");
        return 1;
    }
 
    printf("in sender1()\n");
 
    while (1)
    {
 
        printf("--------------------------------------------\n");
        printf("Now running process is sender1.\n");
 
        if (get_semaphore_value(reply_over31) == 1)//查看当前over31的信号量值 
        {
            close++;
            sem_wait(reply_over31);
        	my_msgrcv(msgid, &msg, "from reveiver1", 31);
        if (strncmp(msg.text, "over13",6) == 0)
        {
            printf("\nreply_over31: %s\n", msg.text);
        }
    	}
 
    if (get_semaphore_value(reply_over41) == 1)
    {
        close++;
        sem_wait(reply_over41);
        my_msgrcv(msgid, (void*)&msg, "from reveiver2", 41);
        if (strncmp(msg.text, "over14",6) == 0)
        {
            printf("\nreply_over41: %s\n", msg.text);
        }
    }
 
    if (close == 2)//说明向两个receiver都不发送消息了 
    {
        break;
    }
 
    printf("\nplease choose who you want to send:");
    scanf("%d", &choice);
    printf("\nchoice is %d\n", choice);
 
    if (choice == 1)
    {
        if (close1 == 0)
        {
 
            msg.type = 13;
            printf("\nplease input your message:");
            scanf("%s", msg.text);
 
            if (strncmp(msg.text, "exit", 4) == 0)
            {
                strcpy(msg.text, "end13");
                my_msgsnd(msgid, &msg, "sender1 to receiver1");
                close1 = 1;
            }
            my_msgsnd(msgid, &msg, "sender1 to receiver1");
        }
        else
        {
            printf("sender1 to receiver1 has ended!\n");
            printf("please input true number,which 1 denotes receiver1,2 denotes receiver2\n");
            scanf("%d", &choice);
            continue;
        }
    }
    else if (choice == 2)
    {
        if (close2 == 0)
        {
            // sem_wait(mutex);
            // sem_wait(&mutex);
 
            msg.type = 14;
            // msg.type = 14;
            printf("\nplease input your message:\n");
            scanf("%s", msg.text);
            // scanf("%s", msg.text);
            printf("msg :%s\n", msg.text);
            // printf("msg :%s\n", msg.text);
 
            if (strncmp(msg.text, "exit", 4) == 0)
            {
                strcpy(msg.text, "end14");
                my_msgsnd(msgid, &msg, "sender1 to receiver2");
                close2 = 1;
            }
            my_msgsnd(msgid, &msg, "sender1 to receiver2");
        }
        else
        {
            printf("sender1 to receiver2 has ended!\n");
            printf("please input true number,which 1 denotes receiver1,2 denotes receiver2\n");
            scanf("%d", &choice);
            continue;
        }
    }
    else
    {
        printf("please input true number,which 1 denotes receiver1,2 denotes receiver2\n");
        scanf("%d", &choice);
        continue;
    }
 
    printf("Sender1 escaped,please look forward to its next coming~.\n");
    printf("--------------------------------------------\n");
}
return 0;
}
 
int main()
{
    run_sender1();
    return 0;
}