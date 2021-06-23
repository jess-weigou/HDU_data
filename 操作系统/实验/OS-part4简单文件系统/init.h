#ifndef INIT_H
#define INIT_H

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define BLOCKSIZE 1024 //磁盘块大小
#define SIZE 1024000  //文件系统最大大小
#define END 65535 //文件结束标志
#define FREE 0  //FAT中盘块空闲标志
#define ROOTBLOCKNM 2
#define MAXOPENFILE 10
#define MAX_TEXT_SIZE 10000//文件最大大小

typedef struct FCB
{
    char filename[8];
    char exname[3];
    unsigned char attribute;
    unsigned short time; //file create time
    unsigned short date;
    unsigned short first;
    unsigned short length;
    char free;
    
}fcb;

typedef struct FAT{
    unsigned short id;
}fat;
//用户打开文件表
typedef struct USEROPENN{
    char filename[8];
    char exname[3];
    unsigned char attribute;
    unsigned short time;
    unsigned short  date;
    unsigned short first;
    unsigned short length;
    char free;

    int dirno;
    int diroff;
    char dir[MAXOPENFILE][80];
    int count;
    char fcbstate; //是否修改 1是 0否
    char topenfile; //打开表项是否为空,0为空
    
}useropen;

typedef struct BLOCK{
    char magic_number[8]; //魔法数字呀
    char information[200]; //细节
    unsigned short root; //根目录文件的起始盘块号
    unsigned char * startblock;  //虚拟磁盘上数据区开始位置
}block0;

unsigned char* myvhard; //指向虚拟磁盘的起始地址
useropen openfilelist[MAXOPENFILE]; //用户打开文件表数组
int currfd;  //当前目录的文件描述符fd
unsigned char* startp; //记录虚拟磁盘上面数据区开始的位置
unsigned char buffer[SIZE];//记录当前目录的目录名

/* sysfile func */
void startsys();
void my_format();
void my_cd(char* dirname);
int do_read(int fd, int len, char* text);
int do_write(int fd, char* text, int len, char wstyle);
int my_read(int fd);
int my_write(int fd);

void exitsys();
void my_cd(char* dirname);
int my_open(char* filename);
int my_close(int fd);
void my_mkdir(char* dirname);
void my_rmdir(char* dirname);
int my_create(char* filename);
void my_rm(char* filename);
void my_ls();
void help();

int get_free_openfilelist();
unsigned short int get_free_block();
#endif