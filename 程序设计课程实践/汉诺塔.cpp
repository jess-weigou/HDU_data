<<<<<<< HEAD
#include<stdio.h> 

void Hanoi(int level,char A,char B,char C)
{
	if (level == 1)//（4）当柱子上只有一个盘子时，直接从A移动到C
	{
		printf("%c->%c\n",A,C);
		return;
	}
	//（1）当盘子数大于1时，先把n-1个从A借助C移动到B。
	Hanoi(level - 1, A, C, B);
	//（2）然后把最后一个从A移动到C。
	printf("%c->%c\n",A,C);
	//（3）再接着把盘子数大于1时，先把n-1个从B借助A移动到C。
	Hanoi(level - 1, B, A, C);
}
int main()
{
	int level=1;

	scanf("%d", &level);
	Hanoi(level,'A','B','C');
	return 0;
} 
=======
#include<stdio.h> 

void Hanoi(int level,char A,char B,char C)
{
	if (level == 1)//（4）当柱子上只有一个盘子时，直接从A移动到C
	{
		printf("%c->%c\n",A,C);
		return;
	}
	//（1）当盘子数大于1时，先把n-1个从A借助C移动到B。
	Hanoi(level - 1, A, C, B);
	//（2）然后把最后一个从A移动到C。
	printf("%c->%c\n",A,C);
	//（3）再接着把盘子数大于1时，先把n-1个从B借助A移动到C。
	Hanoi(level - 1, B, A, C);
}
int main()
{
	int level=1;

	scanf("%d", &level);
	Hanoi(level,'A','B','C');
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
