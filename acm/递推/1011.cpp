#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX 100
#define base 10000 

void cheng(int a[],int Max,int b)
{
	int i;
	int array=0;
	for(i=Max-1;i>=0;i--)
	{
		array+=(a[i]*b);
		a[i]=array%base;
		array/=base;
	}
}


void chu(int a[],int Max,int b)
{
	int i,div=0;
	for(i=0;i<Max;i++)
	{
		div =div * base + a[i];
		a[i] = div/b;
		div=div%b;	
	}
}
int main()
{
	int a[105][MAX];
	int i,j,k,n;
	memset(a[1],0,sizeof(a[1]));
	for(i=2,a[1][MAX-1]=1;i<=100;i++)
	{
		memcpy(a[i],a[i-1],sizeof(a[i-1]));
		cheng(a[i],MAX,(4*i-2));
		chu(a[i],MAX,i+1);
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		for(i=0;i<MAX&&a[n][i]==0;i++);
		printf("%d",a[n][i++]);
		for(;i<MAX;i++)
		{
			printf("%04d",a[n][i]);
		}
		printf("\n");
	}
	return 0;
}
