#include "fuc.h"
 
int run_sender2()
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
    if (msgid == -1)
    {
        printf("msgget failed!\n");
        return 1;
    }
 
    printf("in sender2()\n");
 
    while (1)
    {
 
        printf("--------------------------------------------\n");
        printf("Now running process is sender2.\n");
        // sem_getvalue(reply_over31, &semvalue);
        // sem_getvalue(reply_over31, &semvalue);
        // printf("reply_over31:%d\n", get_semaphore_value(reply_over31));
 
        if (get_semaphore_value(reply_over32) == 1)
        // if (semvalue == 1)
        {
            close++;
            // sem_wait(reply_over31);
            sem_wait(reply_over32);
            // sem_wait(mutex);
            // sem_wait(&mutex);
            // printf("reply_over31:%d\n", get_semaphore_value(reply_over31));
 
            // msgrcv(msgid, (void *)&msg, MAX_TEXT_SIZE, 31, 0);
            // printf("\n%s\n", msg.text);
        // }
			my_msgrcv(msgid, &msg, "from reveiver1", 32);
			if (strncmp(msg.text, "over23",6) == 0)
			{
				printf("\nreply_over32: %s\n", msg.text);
			}
 
        // sem_post(mutex);
        // sem_post(&mutex);
    }
 
    // sem_getvalue(reply_over41, &semvalue);
    // printf("reply_over41:%d\n", get_semaphore_value(reply_over41));
    // sem_getvalue(reply_over41, &semvalue);
    if (get_semaphore_value(reply_over42) == 1)
    // if (semvalue == 1)
    {
        close++;
        // sem_wait(reply_over41);
        sem_wait(reply_over42);
        // sem_wait(mutex);
        // sem_wait(&mutex);
 
    //     msgrcv(msgid, (void *)&msg, MAX_TEXT_SIZE,41, 0);
	//    		printf("\n%s\n", msg.text);
    // }
        my_msgrcv(msgid, &msg, "from reveiver2", 42);
        if (strncmp(msg.text, "over24",6) == 0)
        {
            printf("\nreply_over42: %s\n", msg.text);
        }
 
        // sem_post(mutex);
        // sem_post(&mutex);
    }
 
    if (close == 2)
    {
        break;
    }
 
    printf("\nplease choose who you want to send:\n");
    scanf("%d", &choice);
    printf("\nchoice is %d\n", choice);
 
    if (choice == 1)
    {
        if (close1 == 0)
        {
 
            msg.type = 23;
            // msg.type = 13;
            printf("\nplease input your message:\n");
            scanf("%s", msg.text);
            // scanf("%s", msg.text);
 
            if (strncmp(msg.text, "exit", 4) == 0)
            {
                strcpy(msg.text, "end23");
                my_msgsnd(msgid, &msg, "sender2 to receiver1");
                // sem_post(mutex);
                // sem_post(&mutex);
                close1 = 1;
            }
            my_msgsnd(msgid, &msg, "sender2 to receiver1");
 
            // sem_post(mutex);
            // sem_post(&mutex);
        }
        else
        {
            printf("sender2 to receiver1 has ended!\n");
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
 
            msg.type = 24;
            // msg.type = 14;
            printf("\nplease input your message:\n");
            scanf("%s", msg.text);
            // scanf("%s", msg.text);
            printf("msg :%s\n", msg.text);
            // printf("msg :%s\n", msg.text);
 
            if (strncmp(msg.text, "exit", 4) == 0)
            {
                strcpy(msg.text, "end24");
                my_msgsnd(msgid, &msg, "sender2 to receiver2");
 
                // sem_post(mutex);
                // sem_post(&mutex);
                close2 = 1;
            }
            my_msgsnd(msgid, &msg, "sender2 to receiver2");
 
            // sem_post(mutex);
            // sem_post(&mutex);
        }
        else
        {
            printf("sender2 to receiver2 has ended!\n");
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
 
    printf("Sender2 escaped,please look forward to its next coming~.\n");
    printf("--------------------------------------------\n");
 
    //sem_post(mutex_sender);
 
    // sem_post(mutex_scanner);
    // sem_post(&mutex_scanner);
 
    // sem_post(syn_sender_to_receiver);
    // sem_post(&syn_sender_to_receiver);
}
return 0;
}
 
int main()
{
    run_sender2();
    return 0;
}