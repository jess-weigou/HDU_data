#include "init.h"

key_t key;
int shmid;
void *shmp;

sem_t *send_psx;
sem_t *recv_psx;
sem_t *final_psx;

void init();
void close_all();
void catch_INT(int sig);

//接受到exit自动发送over给sender
int main(void)
{
    char input[SHM_SIZE];
    signal(SIGINT, catch_INT);
    init();
    // recv msg from sender
    while (1) {
        P(recv_psx);
        strcpy(input, (char *)shmp);
        memset((char *)shmp, '\0', SHM_SIZE);
        printf("recv msg: %s\n", input);
        if (strcmp(input, "exit") == 0) {
            strcpy((char *)shmp, "over");
            V(final_psx);
            break;
        }
    }
    close_all();
    printf("receiver end\n");
    return 0;
}
//要receiver输入over才能结束
// int main(){
//     char input[SHM_SIZE];
//     signal(SIGINT, catch_INT);
//     init();
//     while(1){
//         P(recv_psx);
//         strcpy(input, (char*)shmp);
//         memset((char *)shmp, '\0', SHM_SIZE);
//         printf("recv msg: %s\n",input);
//         if (strcmp(input, "exit") == 0){
//             while(1){
//                 scanf("%s",input);
//                 if(strcmp(input, "over")==0){
//                 strcpy((char *)shmp, "over");
//                 V(final_psx);
//                 break;
//             }
//             }
//             break;
            
//         }
//     }
//     close_all();
//     printf("receive end\n");
//     return 0;
// }

void init(){
    key = KEY_NUM;
    //创建共享内存
     //IPC internet process connect 命名管道
    //shmid share memorize id 共享内存标识符
    //shmget share memorize get 创建共享内存空间
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    if(shmid < 0){
        printf("shmget error\n");
        exit(1);
    }
    //share member attach 启动对共享内存的访问
    shmp = shmat(shmid, NULL, 0);
    send_psx = sem_open("sem_send", O_CREAT, 0666, 1);
    recv_psx = sem_open("sem_recv", O_CREAT, 0666, 0);
    final_psx = sem_open("sem_fin", O_CREAT, 0666, 0);
}

void close_all(){
    sem_close(send_psx);
    sem_close(recv_psx);
    sem_close(final_psx);
    //share member detach 将共享内存从当前进程中分离
    shmdt(shmp);
}

void catch_INT(int sig){
    printf("catch SIGINT\n");
    close_all();
    exit(0);
}


