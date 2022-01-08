#include<stdio.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>


typedef struct {
	int i;
	int j;//数组下标
} Point;

void GotoXY(int, int);	//光标定位函数
void Hide();			//隐藏光标函数
void InitMaze();
int Move();
void Win();
void Lose();
int Menu();
void Help();
