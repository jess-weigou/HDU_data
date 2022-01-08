<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char map[101][101];
int vis[101][101];
int a,b,k=0;
struct node{
	int x,y;
};
int go[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
void bfs()
{
	queue<node> q;
	node now,nex;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(vis[i][j]==0)
			{
				now.x=i;
				now.y=j;
				vis[i][j]=1;
				k++;
				q.push(now);
				while(!q.empty())
				{
					nex=q.front();
					q.pop();
					for(int i=0;i<8;i++)
					{
						int m=nex.x+go[i][0];
						int n=nex.y+go[i][1];
						if(m>0&&m<=a&&n>0&&n<=b)
						{
							if(vis[m][n]==0)
							{
								now.x=m;
								now.y=n;
								vis[m][n]=1;
								q.push(now);
							}
						}
					}
				}
			}	
		}
	}
	printf("%d\n",k);
	k=0;
}
int main()
{
	
	while(scanf("%d %d ",&a,&b)!=EOF)
	{
		if(a==0&&b==0) break;
		int i=1,j=1;
		memset(vis,0,sizeof(vis));
		
		while(i<=a)
		{
			while(j<=b)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='\n') j--;
				if(map[i][j]=='*') vis[i][j]=1;
				j++;
			}
			i++;
			j=1;
		} 
//		for(i=1;i<=a;i++){
//			for( j=1;j<=b;j++) printf("%d  ",vis[i][j]); 
//			printf("\n");
//		}
		bfs();
	}
} 
=======
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char map[101][101];
int vis[101][101];
int a,b,k=0;
struct node{
	int x,y;
};
int go[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
void bfs()
{
	queue<node> q;
	node now,nex;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(vis[i][j]==0)
			{
				now.x=i;
				now.y=j;
				vis[i][j]=1;
				k++;
				q.push(now);
				while(!q.empty())
				{
					nex=q.front();
					q.pop();
					for(int i=0;i<8;i++)
					{
						int m=nex.x+go[i][0];
						int n=nex.y+go[i][1];
						if(m>0&&m<=a&&n>0&&n<=b)
						{
							if(vis[m][n]==0)
							{
								now.x=m;
								now.y=n;
								vis[m][n]=1;
								q.push(now);
							}
						}
					}
				}
			}	
		}
	}
	printf("%d\n",k);
	k=0;
}
int main()
{
	
	while(scanf("%d %d ",&a,&b)!=EOF)
	{
		if(a==0&&b==0) break;
		int i=1,j=1;
		memset(vis,0,sizeof(vis));
		
		while(i<=a)
		{
			while(j<=b)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='\n') j--;
				if(map[i][j]=='*') vis[i][j]=1;
				j++;
			}
			i++;
			j=1;
		} 
//		for(i=1;i<=a;i++){
//			for( j=1;j<=b;j++) printf("%d  ",vis[i][j]); 
//			printf("\n");
//		}
		bfs();
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
