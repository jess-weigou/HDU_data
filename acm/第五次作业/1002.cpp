<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int max1(int a,int b,int c)
{
	if(a>=b&&a>=c) return a;
	else if(b>=a&&b>=c) return b;
	else return c;
}
int max2(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int shuzu[100010][12];
	int n,a,b,maxn=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(shuzu,0,sizeof(shuzu));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			shuzu[b][a]++;
			if(b>maxn) maxn=b;
		}
//		printf("%d",maxn);
		for(int i=maxn-1;i>=0;i--)
		{
			shuzu[i][0]+=max2(shuzu[i+1][0],shuzu[i+1][1]);
			for(int j=1;j<=10;j++)
			{
				shuzu[i][j]+=max1(shuzu[i+1][j],shuzu[i+1][j+1],shuzu[i+1][j-1]);
			}
		}
		printf("%d\n",shuzu[0][5]);
	}
} 
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int max1(int a,int b,int c)
{
	if(a>=b&&a>=c) return a;
	else if(b>=a&&b>=c) return b;
	else return c;
}
int max2(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int shuzu[100010][12];
	int n,a,b,maxn=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(shuzu,0,sizeof(shuzu));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			shuzu[b][a]++;
			if(b>maxn) maxn=b;
		}
//		printf("%d",maxn);
		for(int i=maxn-1;i>=0;i--)
		{
			shuzu[i][0]+=max2(shuzu[i+1][0],shuzu[i+1][1]);
			for(int j=1;j<=10;j++)
			{
				shuzu[i][j]+=max1(shuzu[i+1][j],shuzu[i+1][j+1],shuzu[i+1][j-1]);
			}
		}
		printf("%d\n",shuzu[0][5]);
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
