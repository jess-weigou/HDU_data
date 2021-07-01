#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 101
int number[N];
void start()
{
	for(int i=2;i<=sqrt(N);i++)
	{
		for(int j=i*2;j<=N;j+=i)
		{
			number[j]=1;   
		}
	}
} 
int main()
{
	int n,sum,a;
	memset(number,0,sizeof(number));
	start();
	while(scanf("%d",&a)!=EOF)
	{
		if(a==1)
		{
			printf("0\n");
			continue;
		}else if(a==4){
			printf("1\n");
			continue;
		} 
		while(number[a-1]==1)
		{
			a--;
		}
		printf("%d\n",a-1);
	}
//	for(int i=1;i<N;i++)
//	{
//		if(number[i]!=1)
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
} 

