<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int n;
	long long int f[55];
	f[0]=1;
	f[1]=2;
	f[2]=3;
	for(int i=3;i<55;i++)
	{
		f[i]=f[i-1]+f[i-3];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		printf("%lld\n",f[n-1]);
	}                                                                                           
} 
=======
#include<stdio.h>
int main()
{
	int n;
	long long int f[55];
	f[0]=1;
	f[1]=2;
	f[2]=3;
	for(int i=3;i<55;i++)
	{
		f[i]=f[i-1]+f[i-3];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		printf("%lld\n",f[n-1]);
	}                                                                                           
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
