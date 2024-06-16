<<<<<<< HEAD
#include<stdio.h>//long long int 要用“%lld” 
int main()
{
	int k;
	long long int f[51];
	f[1]=3;
	f[2]=6;
	f[3]=6;
	for(int i=4;i<51;i++)
	{
		f[i]=f[i-1]+2*f[i-2];
	}
	while(scanf("%d",&k)!=EOF)
	{
		printf("%lld\n",f[k]);
	}
	return 0;
} 
=======
#include<stdio.h>//long long int 要用“%lld” 
int main()
{
	int k;
	long long int f[51];
	f[1]=3;
	f[2]=6;
	f[3]=6;
	for(int i=4;i<51;i++)
	{
		f[i]=f[i-1]+2*f[i-2];
	}
	while(scanf("%d",&k)!=EOF)
	{
		printf("%lld\n",f[k]);
	}
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
