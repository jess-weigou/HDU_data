<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
char map[11][11];
struct vis{
	int a,b;
}vis[11][11];
int main()
{
	int a,b,c;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a==0||b==0) break;
		scanf("%d",&c);
		getchar();
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%c",&map[i][j]); 
			}
			getchar();
		}
		memset(vis,0,sizeof(vis));
		int i=1,j=c;
		vis[i][c].a=1;
		vis[i][c].b=0;
		int n=0;
		while(1)
		{
			if(i<=0||j<=0||i>a||j>b)
			{
				printf("%d step(s) to exit\n",n);
				break;
			}
			
			if(map[i][j]=='N')
			{
				i--;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i+1][j].b+1;
				}else{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
				
			} 
			else if(map[i][j]=='S')
			{
				i++;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i-1][j].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			else if(map[i][j]=='W')
			{
				j--;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i][j+1].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			else if(map[i][j]=='E')
			{
				j++;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i][j-1].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			
		}	
	}
} 
=======
#include<stdio.h>
#include<string.h>
char map[11][11];
struct vis{
	int a,b;
}vis[11][11];
int main()
{
	int a,b,c;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a==0||b==0) break;
		scanf("%d",&c);
		getchar();
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%c",&map[i][j]); 
			}
			getchar();
		}
		memset(vis,0,sizeof(vis));
		int i=1,j=c;
		vis[i][c].a=1;
		vis[i][c].b=0;
		int n=0;
		while(1)
		{
			if(i<=0||j<=0||i>a||j>b)
			{
				printf("%d step(s) to exit\n",n);
				break;
			}
			
			if(map[i][j]=='N')
			{
				i--;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i+1][j].b+1;
				}else{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
				
			} 
			else if(map[i][j]=='S')
			{
				i++;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i-1][j].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			else if(map[i][j]=='W')
			{
				j--;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i][j+1].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			else if(map[i][j]=='E')
			{
				j++;
				n++;
				if(vis[i][j].a!=1)
				{
					vis[i][j].a=1;
					vis[i][j].b=vis[i][j-1].b+1;
				}else
				{
					
					printf("%d step(s) before a loop of %d step(s)\n",vis[i][j].b,n-vis[i][j].b);
					break;
				}
			} 
			
		}	
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
