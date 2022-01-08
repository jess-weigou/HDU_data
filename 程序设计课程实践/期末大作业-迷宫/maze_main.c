#include "maze.h"
int main() {
	int end = 1, result;
	while (end) {
		result = Menu();			 //显示主菜单，并根据用户选择菜单选项决定游戏的执行
		switch (result) {
		case 1:					 //选择1表示，开始游戏
			InitMaze();			 //初始化
			while (Move());
			//如果返回0，则结束；返回1，继续
			break;
		case 2:					  //选择2表示，显示帮助信息
			Help();
			break;
		case 3:					  //选择3表示，显示关于信息
			About();
			break;
		case 0:					  //选择0表示，表示结束程序
			end = 0;
			
			break;
		}
	}
	return 0;
}