#include<stdio.h>
#include<string.h>
#define N 800
int link[N][N],used[N],boy[N];
int count,n;
bool find(int n1)
{
	for(int i=1;i<=n;i++)
	{
		if(link[n1][i]==1&&!used[i])
		{
			used[i]=true;
			if(!boy[i]||find(boy[i]))
			{
				boy[i]=n1;
				return true;
			}
			
		}
	}
	return false;
}
int main()
{
	int a,c,d;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(link,0,sizeof(link));
		memset(boy,0,sizeof(boy));
		count=0;
		
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&link[i][j]);
			} 	
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(link[i][j]==1) link[j][i]=0;
			} 	
		} 
		for(int i=1;i<=n;i++)
		{
			memset(used,false,sizeof(used)); 
			if(find(i))
			{
				count++;
			} 
		}	
		printf("%d\n",count);
	}
} 
