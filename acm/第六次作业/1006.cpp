<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int v[110];
	int w[110];
	int dp[100005];
	int n,l,flag;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d %d",&v[i],&w[i]);	
		scanf("%d",&l);
		for(int i=1;i<=n;i++)
		{
			for(int j=w[i];j<=l;j++)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);	
			}
		}
		printf("%d\n",dp[l]);
	}
	return 0;
} 
=======
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int v[110];
	int w[110];
	int dp[100005];
	int n,l,flag;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d %d",&v[i],&w[i]);	
		scanf("%d",&l);
		for(int i=1;i<=n;i++)
		{
			for(int j=w[i];j<=l;j++)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);	
			}
		}
		printf("%d\n",dp[l]);
	}
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
