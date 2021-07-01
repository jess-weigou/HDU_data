#include<stdio.h>
#include"maze.h"
Point point;

int m=0;//二维数组第一维
int n=0;//二维数组第二维
int** maze;
FILE* fp;
int stepcount = 0;//步数
clock_t starttime, endtime;

int Menu() {
	GotoXY(4, 2); 			     //定位光标位置
	printf("欢迎来到迷宫小游戏");
	GotoXY(4, 4);
	printf("1.开始游戏");
	GotoXY(4, 6);
	printf("2.帮助");
	GotoXY(4, 8);
	printf("3.关于");
	GotoXY(4, 10);
	printf("其他任意键退出游戏");
	Hide();	                       //隐藏光标
	char ch;
	int result = 0;
	maze = NULL;
	fp = NULL;
	starttime = NULL;
	endtime = NULL;
	stepcount = 0;
	ch = _getch();   			    //接收用户输入的菜单选项
	switch (ch) {				//根据选项设置返回结果值
	case '1': result = 1; break;
	case '2': result = 2; break;
	case '3': result = 3; break;
	default:
		if (maze != NULL) {
			for (int i = 0; i < m; i++)
				free(maze[i]);
			free(maze);
		}
		if (fp != NULL) {
			fclose(fp);
		}
		break;
	}

	system("cls");  				//调用系统命令cls完成清屏操作
	return result;
}

void GotoXY(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);   
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}

/*隐藏光标*/
void Hide() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1, 0 };
	SetConsoleCursorInfo(hout, &cor_info);
}

void About() {
	GotoXY(4, 2);
	printf("杭州电子科技大学--程序设计综合实践");
	GotoXY(4, 4);
	printf("迷宫游戏");
	GotoXY(4, 6);
	printf("按任意键返回上级菜单");
	Hide();		//隐藏光标
	char ch = _getch();
	system("cls");
}

void Help() {
	GotoXY(4, 2);
	printf("w 上");
	GotoXY(4, 4);
	printf("s 下");
	GotoXY(4, 6);
	printf("a 左");
	GotoXY(4, 8);
	printf("d 右");
	GotoXY(4, 10);
	printf("触碰到怪兽时失败，走到出口时赢得游戏");
	GotoXY(4, 12);
	printf("输入文件格式为宽 高\\n矩阵");
	GotoXY(4, 14);
	printf("按任意键返回上级菜单");
	Hide();		//隐藏光标
	char ch = _getch();
	system("cls");
}

void InitMaze() {
	system("cls");
	Hide();
	int y = 2;
	GotoXY(4, y);
	if (fp == NULL) {
		fp = fopen("maze.txt", "r");
		fscanf(fp, "%d", &m);
		fscanf(fp, "%d\n", &n);
	}
	
	if (maze == NULL) {
		maze = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++)
			maze[i] = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d ", &maze[i][j]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 1) {
				printf("█");//wall
			}
			else if (maze[i][j] == 0) {
				printf("□"); //road
			}
			else if (maze[i][j] == 2) {
				printf("◎"); //monster
			}
			else if (maze[i][j] == 3) {
				printf("★"); //begin
				point.i = i;
				point.j = j;   
			}
			else if (maze[i][j] == 4) {
				printf("卐"); //end
			}
		}
		GotoXY(4, ++y);
	}

	
}

int Move() {
	char ch = getch();

	switch (ch) {
	case'w':
	case'W':
		if (maze[point.i-1][point.j] != 1) {
			if (maze[point.i-1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i-1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i--;
			maze[point.i][point.j] = 3;
		}
		break;

	case'a':
	case'A':
		if (maze[point.i][point.j - 1] != 1) {
			if (maze[point.i][point.j-1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j-1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j--;
			maze[point.i][point.j] = 3;
		}
		break;

	case's':
	case'S':
		if (maze[point.i + 1][point.j] != 1) {
			if (maze[point.i + 1][point.j] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i + 1][point.j] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.i++;
			maze[point.i][point.j] = 3;
		}
		break;

	case'd':
	case'D':
		if (maze[point.i][point.j + 1] != 1) {
			if (maze[point.i][point.j + 1] == 2) {
				Lose();
				return 0;
			}
			if (maze[point.i][point.j + 1] == 4) {
				endtime = clock(NULL);
				Win();
				return 0;
			}
			maze[point.i][point.j] = 0;
			point.j++;
			maze[point.i][point.j] = 3;
		}
		break;
	default:
		system("cls");
		return 0;
	}
	
	if (starttime == NULL) starttime = clock();
	stepcount++;
	InitMaze();
	return 1;
}

void Win() {
	system("cls");
	GotoXY(4, 2);
	printf("You Win!");
	GotoXY(4, 4);
	printf("您所用的步数为%d",stepcount);
	GotoXY(4, 6);
	printf("您的用时为%d秒", (int)(endtime-starttime)/CLOCKS_PER_SEC);
	GotoXY(4, 8);
	printf("按任意键返回主菜单");
	Hide();		//隐藏光标
	char ch = _getch();
	system("cls");
}

void Lose() {
	system("cls");
	GotoXY(4, 2);
	printf("你输了,请再尝试一遍");
	GotoXY(4, 4);
	printf("按任意键返回主菜单");
	Hide();		//隐藏光标
	char ch = _getch();
	system("cls");
}
