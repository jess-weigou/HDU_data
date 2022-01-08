#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int vis[52][52][52];
int map[52][52][52];
int go[6][3] = {1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
int x,y,z,t;
struct node
{
    int x,y,z,t;
    
};
bool check(int a,int b,int c){

	if(a<0 || a>=x|| b<0 || b>=y || c<0 || c>=z ) return 0;
    if(vis[a][b][c] || map[a][b][c])   return 0;
	return 1;
}
void bfs(){
	queue<node> Q;
    node now,nex;
    now.x = 0;
	now.y = 0;
	now.z = 0;
    now.t = 0;
    vis[0][0][0] = 1;
    Q.push(now);
    while(!Q.empty()){
    	nex=Q.front();
    	Q.pop();
    	if(nex.x==x-1&&nex.y==y-1&&nex.z==z-1){
    		printf("%d\n",nex.t);
    		return ;
		} 
		if(nex.t>t){
			printf("-1\n");//时间到 
			return ;
		}
		for(int i=0;i<6;i++){
				now.x=nex.x+go[i][0];
				now.y=nex.y+go[i][1];
				now.z=nex.z+go[i][2];
				
				if(check(now.x,now.y,now.z)){
						now.t=nex.t+1;
						Q.push(now);
						vis[now.x][now.y][now.z]=1;
				}
		}
    }
    printf("-1\n");//找不到 
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d",&x,&y,&z,&t);
		
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				for(int k=0;k<z;k++)
				  scanf("%d",&map[i][j][k]);
		memset(vis,0,sizeof(vis));
		bfs();
	}
}
