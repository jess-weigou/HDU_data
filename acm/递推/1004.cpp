<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int n;
	long long int f[50];
	f[0]=1;
	f[1]=2;
	for(int i=2;i<50;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",f[n-1]);
	}                                                                                           
} 
=======
#include<stdio.h>
int main()
{
	int n;
	long long int f[50];
	f[0]=1;
	f[1]=2;
	for(int i=2;i<50;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",f[n-1]);
	}                                                                                           
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
