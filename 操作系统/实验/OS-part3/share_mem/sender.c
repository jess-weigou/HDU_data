#include"init.h"

key_t key;
//share_member_id 共享内存id,共享内存标识符
int shmid;

void *shmp;
//发送信号量
sem_t *send_psx;
sem_t *recv_psx;
sem_t *final_psx;

void init();
void close_all();
void catch_INT(int sig);
void destroy();
int check_value(sem_t *semtmp, int style);
int main(){
    int ret = -1;
    char input[SHM_SIZE];
    char info[SHM_SIZE];
    
    signal(SIGINT, catch_INT);
    init();
    memset(input, '\0',sizeof(input));
    while(1){
        printf("please input: ");
        scanf("%s", input);
        P(send_psx);
        strcpy(info, (char *)shmp);
        strcat(info, input);
        strcpy((char *)shmp, info);
        
        //如果接受到exit
        if(strcmp(input, "exit") == 0){
            ret = check_value(recv_psx, 0);
            if(ret == 1){
                V(recv_psx);
            }
            break;
        }
        memset(input, '\0', sizeof(input));
        ret = check_value(recv_psx, 0);
        if(ret == 1){
            V(recv_psx);
        }
        V(send_psx);
    }
    P(final_psx);
    strcpy(input, (char *)shmp);
    printf("sender recv: %s\n", input);
    destroy();
    printf("sender end\n");
    return 0;
}

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
    destroy();
    exit(0);
}

void destroy(){
    shmdt(shmp);
    //share member control RMID是删除共享内存段.
    shmctl(shmid, IPC_RMID, NULL);
    sem_unlink("sem_send");
    sem_unlink("sem_recv");
    sem_unlink("sem_fin");
}

int check_value(sem_t *semtmp, int style){
    int ret = -1,sem_vl;
    ret = sem_getvalue(semtmp, &sem_vl);
    if(ret == -1){
        printf("get sem value error\n");
        destroy();
        exit(0);
    }
    if(style == 0){
        if(sem_vl == 0)
            return 1;
        else 
            return 0;
    }

}

