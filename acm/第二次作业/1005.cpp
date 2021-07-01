#include<stdio.h>
const int N=1000000+5;
int main()
{
	long long f[N];
	long int a ;
	f[0]=7;
	f[1]=11;
	for(long int i=2;i<1000000;i++)
	{
		f[i]=(f[i-1]+f[i-2])%3;
	}
	while(scanf("%d",&a)!=EOF)
	{
		if(f[a]==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
} 
