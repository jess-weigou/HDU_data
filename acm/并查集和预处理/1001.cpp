#include<stdio.h>
#include<string.h>
int a,b;
int num[102][102],door[102][102];
int dfs(int x,int y)
{
	if(door[x][y]>=0) return door[x][y];
	door[x][y]=0;
	for(int i=0;i<=num[x][y];i++)
	{
		for(int j=0;j<=num[x][y]-i;j++)
		{
			if((x+i)>a||(y+j)>b||x<=0||y<=0) continue;
			int t=dfs(x+i,y+j);
			door[x][y]=(door[x][y]+t)%10000;
		}
	}
	return door[x][y];
} 
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(door,-1,sizeof(door));
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		door[a][b]=1;
		int t=dfs(1,1);
		printf("%d\n",t);
	}
} 
