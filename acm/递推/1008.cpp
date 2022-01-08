<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int n,a;
	long long int f[50];
	f[0]=1;
	f[1]=3;
	for(int i=2;i<30;i++)
	{
		f[i]=f[i-1]+2*f[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%lld\n",f[a-1]);
	}                                                                                           
} 
=======
#include<stdio.h>
int main()
{
	int n,a;
	long long int f[50];
	f[0]=1;
	f[1]=3;
	for(int i=2;i<30;i++)
	{
		f[i]=f[i-1]+2*f[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%lld\n",f[a-1]);
	}                                                                                           
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
