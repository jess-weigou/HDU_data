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
