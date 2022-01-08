#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[20][20];//代表迷宫大小
int a,b,t,flag;//di，dj代表结束位置
int si,sj,di,dj;     //si，sj代表开始位置
int vis[7][7]; //代表是否走过
int dir[4][2]={-1,0,0,-1,1,0,0,1} ;//方向：上左下右
FILE* fp,*fp2;
void dfs(int x,int y)
{
	if(x==di&&y==dj){
		flag=1;
		vis[x][y] = 4;
 	}
	if(flag==1) return;
	if(x<=0||x>a||y<=0||y>b) return ;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(vis[xx][yy]==0)
		{
			vis[xx][yy]=2;
			dfs(xx,yy);
			if(flag ==0)
				vis[xx][yy] = 0;
			else{
				break;
			}
		}
	} 
}

//迷宫数字代表的意思：1是围墙,2是怪兽,3是起点,4是终点
int main()
{
	
	fp = fopen("maze.txt", "r");
	fscanf(fp, "%d%d\n", &a,&b);
	if(a==0 || b==0)  return 0;
	int i=1,j=1;
	int sum =0;
	flag=0;
	memset(vis,0,sizeof(vis));
	while(i<=a)
	{
		while(j<=b)
			{
				fscanf(fp,"%d",&map[i][j]);
				if(map[i][j]=='\n') j--;
				if(map[i][j]==3){ //如果遇到开始符号
					si=i;sj=j;
					vis[si][sj]=1;
				} 
				else if(map[i][j]==1||map[i][j]==2) //如果遇到围墙或者怪兽
				{
					vis[i][j]=1;
					sum++;
				}else if(map[i][j]==4){ //如果遇到结束符号
					di=i;dj=j;
				}
				j++;
			}
			i++;
			j=1;
		}
	dfs(si,sj);
	vis[si][sj] = 3;
	if(flag==1){
		printf("YES\n");
		fp2 = fopen("router.txt", "w+");
		for(i=1;i<=a;i++)
			for(int j=1;j<=b;j++){
				if(j==b){
					fprintf(fp2,"%d\n", vis[i][j]);
				}else
					fprintf(fp2,"%d ", vis[i][j]);
			}
		 }
	else printf("NO\n");
	for(i=1;i<=a;i++)
		for(int j=1;j<=b;j++){
			if(j==b){
				printf("%d\n",vis[i][j]);
			}else
				printf("%d ",vis[i][j]);
		}

	return 0;
}