#include<stdio.h>
int main()
{
	int n,a,f[20];
	scanf("%d",&n);
	f[0]=3;
	f[1]=7;
	for(int i=2;i<20;i++)
	{
		f[i]=2*f[i-1]+f[i-2];
	}
	while(n--)
	{
		scanf("%d",&a);
		printf("%d\n",f[a-1]);
	}
} 
