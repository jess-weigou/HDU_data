<<<<<<< HEAD
//要从前面到后面，2到a，然后 memset(dp,9999,sizeof(dp[0]));是没用的 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	
	int dp[21][11];
	int shuzu[21][11];
	int a,b;
	int min1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		memset(shuzu,0,sizeof(shuzu));
		memset(dp,9999,sizeof(dp));
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%d",&shuzu[i][j]);
			} 
		} 
		for(int i=1;i<=b;i++)
		{
			dp[1][i]=0;
		}
		for(int i=2;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=b;k++){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(shuzu[i][j]-shuzu[i-1][k]));
				} 
			}
		}
		min1=9999;
		for(int j=1;j<=b;j++)
		{
			min1=min(min1,dp[a][j]);
		} 
		printf("%d\n",min1);
	
	}
}
=======
//要从前面到后面，2到a，然后 memset(dp,9999,sizeof(dp[0]));是没用的 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	
	int dp[21][11];
	int shuzu[21][11];
	int a,b;
	int min1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		memset(shuzu,0,sizeof(shuzu));
		memset(dp,9999,sizeof(dp));
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%d",&shuzu[i][j]);
			} 
		} 
		for(int i=1;i<=b;i++)
		{
			dp[1][i]=0;
		}
		for(int i=2;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=b;k++){
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(shuzu[i][j]-shuzu[i-1][k]));
				} 
			}
		}
		min1=9999;
		for(int j=1;j<=b;j++)
		{
			min1=min(min1,dp[a][j]);
		} 
		printf("%d\n",min1);
	
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
