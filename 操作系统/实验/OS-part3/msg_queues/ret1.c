#include "fuc.h"
 
int run_receiver1()
{
    int close1 = 0;
    int close2 = 0;
    int semvalue;
    message msg;
    int choice;
    int msgid;
 
    sem_t *reply_over31;
    sem_t *reply_over41;
    sem_t *reply_over32;
    sem_t *reply_over42;
 
    //sem_init(&re0,0);
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
 
    printf("in function receiver1()\n");
 
    while (1)
    {
        // sem_wait(mutex_receiver);
        // sem_wait(syn_sender_to_receiver);
        // sem_wait(&syn_sender_to_receiver);
 
        // sem_wait(mutex_scanner);
        // sem_wait(&mutex_scanner);
 
        printf("--------------------------------------------\n");
        printf("Now running process is receiver1.\n");
        // printf("mutex_scanner:%d\n", get_semaphore_value(&mutex_scanner));
 
        printf("\nplease choose message from sender,which 1 denotes sender1,2 denotes sender2\n");
 
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (close1 == 0)
            {
                // sem_wait(mutex);
                // sem_wait(&mutex);
 
                if (msgrcv(msgid, (void *)&msg, MAX_TEXT_SIZE, 13, IPC_NOWAIT) ==-1)
                {
                    printf("There is no message from sender1!\n");
                }
                else
                {
 
                    printf("There is one message from sender1:\n%s\n\n", msg.text);
 
                    if (strncmp(msg.text, "end13", 5) == 0)
                    {
                        close1 = 1;
                        // sem_post(reply_over31);
                        // printf("reply_over31:%d\n", get_semaphore_value(reply_over31));
                        printf("reply_over31:%d\n", get_semaphore_value(reply_over31));
                        strcpy(msg.text, "over13");
                        msg.type = 31;
 
                        my_msgsnd(msgid, &msg, "receiver1 to sender1");
                        sem_post(reply_over31);
 
                        // sem_post(mutex);
                        // sem_post(&mutex);
                    }
 
                    // sem_post(mutex);
                    // sem_post(&mutex);
                }
            }
            else
            {
                printf("sender 1 to receiver 1 is closed!\n");
                printf("please input true number,which 1 denotes sender1,2 denotes sender2\n");
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
 
                if (msgrcv(msgid, (void *)&msg, MAX_TEXT_SIZE, 23, IPC_NOWAIT) ==-1 )
                {
                    printf("There is no message from sender2!\n\n");
                }
                else
                {
 
                    printf("There is one message from sender2:\n%s\n\n", msg.text);
                    if (strncmp(msg.text, "end23", 5) == 0)
                    {
                        close2 = 1;
                        // sem_post(reply_over31);
                        printf("reply_over32:%d\n",get_semaphore_value(reply_over32));
                        strcpy(msg.text, "over23");
                        msg.type = 32;
 
                        my_msgsnd(msgid, &msg, "receiver1 to sender2");
                        sem_post(reply_over32);
 
                        // sem_post(mutex);
                        // sem_post(&mutex);
                    }
 
                    // sem_post(mutex);
                    // sem_post(&mutex);
                }
            }
            else
            {
                printf("sender 2 to receiver 1 is closed!\n");
                printf("please input true number,which 1 denotes sender1,2 denotes sender2\n");
                scanf("%d", &choice);
                continue;
            }
        }
        else
        {
            printf("please input true number,which 1 denotes sender1,2 denotes sender2\n");
            scanf("%d", &choice);
            continue;
        }
        if (close1 == 1 && close2 == 1)
        {
            printf("all roads closed, over!\n");
            break;
        }
 
        printf("Receiver1 escaped,please look forward to its next coming~.\n");
        printf("--------------------------------------------\n");
 
        // sem_post(mutex_receiver);
        // sem_post(mutex_scanner);
        // sem_post(&mutex_scanner);
    }
    return 0;
}
 
int main()
{
    run_receiver1();
    return 0;
}