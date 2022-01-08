#include<stdio.h>
int main()
{
	int n,a,b;
	long long int f[50];
	f[1]=1;
	f[2]=2; 
	f[3]=3;
	f[4]=5;
	for(int i=5;i<50;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%lld\n",f[b-a]);
	}
} 
