#include<stdio.h>
int c1[10001],c2[10001];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(int i=0;i<=n;i++)
		{
			c1[i]=1;
			c2[i]=0;
		} 
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k+j<=n;k+=i*i)
				{
					c2[j+k]+=c1[j]; 
				}
			}
			for(int p=0;p<=n;p++)
			{
				c1[p]=c2[p];
				c2[p]=0;
			} 
		}
		printf("%d\n",c1[n]);
	}
} 
