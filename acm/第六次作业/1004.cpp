<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if (a>b ) return a;
	else return b;
}
int main()
{
	int n,a,b;
	int v[5002],sum;
	float average;
	int dp[255002];
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0) break;
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		sum=0;
		int l=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			while(b--){
				v[++l]=a;
				sum+=a; 
			}
		}
		average=(float)sum/2;
		for(int i=1;i<=l;i++)
		{
			for(int j=sum/2;j>=v[i];j--)
			{
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
			} 
		}
		printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
	}
	return 0;
} 
=======
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if (a>b ) return a;
	else return b;
}
int main()
{
	int n,a,b;
	int v[5002],sum;
	float average;
	int dp[255002];
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0) break;
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		sum=0;
		int l=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			while(b--){
				v[++l]=a;
				sum+=a; 
			}
		}
		average=(float)sum/2;
		for(int i=1;i<=l;i++)
		{
			for(int j=sum/2;j>=v[i];j--)
			{
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
			} 
		}
		printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
	}
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
