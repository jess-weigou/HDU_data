<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<math.h>
#define  N 1000001 
int b[1000001];

bool is(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
void start()
{
	int k=0;
	for(int i=1;i<N;i++)
	{
		if(is(i))
		{
			for(int j=1;i*j<N;j++)
			{
				b[j*i]=k;
			}
			k++;
		}
	}
} 
int main()
{
	int a;
	start();
	while(scanf("%d",&a)!=EOF)
	{
		printf("%d\n",b[a]);
	}

} 
=======
#include<stdio.h>
#include<string.h>
#include<math.h>
#define  N 1000001 
int b[1000001];

bool is(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
void start()
{
	int k=0;
	for(int i=1;i<N;i++)
	{
		if(is(i))
		{
			for(int j=1;i*j<N;j++)
			{
				b[j*i]=k;
			}
			k++;
		}
	}
} 
int main()
{
	int a;
	start();
	while(scanf("%d",&a)!=EOF)
	{
		printf("%d\n",b[a]);
	}

} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
