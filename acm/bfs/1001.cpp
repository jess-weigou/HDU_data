/*可以用getchar（）接收换行*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char map[9][9];
int a,b,t,di,dj,flag;
int si,sj;
int vis[9][9];
int dir[4][2]={0,1,1,0,0,-1,-1,0} ;//方向：右下左上 
void dfs(int x,int y,int step)
{
	if(x==di&&y==dj&&step==t){
		flag=1;
	}
	if(flag==1) return;
	if(x<=0||x>a||y<=0||y>b) return ;
	int ans=t-step-abs(di-x)-abs(dj-y);//奇偶 剪纸 
	if(ans<0||ans&1) return;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(vis[xx][yy]==0)
		{
			vis[xx][yy]=1;
			dfs(xx,yy,step+1);
			vis[xx][yy]=0;
		}
	} 
}
int main()
{
	
	while(scanf("%d %d %d",&a,&b,&t)!=EOF)
	{
		getchar();
		if(a==0&&b==0&&t==0) break;
		int i=1,j=1,sum=0;
		flag=0;
		memset(vis,0,sizeof(vis));

		while(i<=a)
		{
			while(j<=b)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='\n') j--;
				if(map[i][j]=='S'){
					si=i;sj=j;
				} 
				else if(map[i][j]=='X')
				{
					vis[i][j]=1;
					sum++;
				} 
				else if(map[i][j]=='D'){
					di=i;dj=j;
				} 
				j++;
			}
			i++;
			j=1;
		} 
		if(a*b-sum<t){
			printf("NO\n");
		}else{
			vis[si][sj]=1;
			dfs(si,sj,0);
			if(flag==1) printf("YES\n");
			else printf("NO\n");
		}
		
	}
	return 0;
}
