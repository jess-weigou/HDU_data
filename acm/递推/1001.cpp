#include<stdio.h>
int main()
{
	int n,a;
	long long int f[50];
	f[1]=1;
	f[2]=3;
	for(int i=3;i<=40;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%lld\n",f[a]);
	}                                                                                           
} 
