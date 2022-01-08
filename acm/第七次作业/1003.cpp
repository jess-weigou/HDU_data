<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<queue>
using namespace std;
int vis[10][10];
int go[8][2] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
struct node
{
    int x,y;
    int count;
   
};
int bfs(int a,int b,int c,int d){
	
	queue<node> Q;
    node now,nex;
    now.x = a;
	now.y = b;
    now.count = 0;
    vis[now.x][now.y] = 1;
    Q.push(now);
    while(!Q.empty()){
    	nex=Q.front();
    	Q.pop();
		if(nex.x==c&&nex.y==d) return nex.count;
		for(int i=0;i<8;i++)
		{
			if(nex.x+go[i][0]>0&&nex.x+go[i][0]<=8&&nex.y+go[i][1]>0&&nex.y+go[i][1]<=8)
			{
				if(vis[nex.x+go[i][0]][nex.y+go[i][1]]==0){
					now.x=nex.x+go[i][0];
					now.y=nex.y+go[i][1];
					now.count=nex.count+1;
					vis[now.x][now.y]=1;
					Q.push(now);
				}
			}
		}
	}
	return -1;
}
int main(){
	char s1[2],s2[2];
	while(scanf("%s %s",&s1,&s2)!=EOF){
		int y1=s1[0]-'a'+1;
		int x1=s1[1]-48;
		int y2=s2[0]-'a'+1;
		int x2=s2[1]-48;
		for(int i=0;i<10;i++) 
			for(int j=0;j<10;j++) vis[i][j]=0;
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs(x1,y1,x2,y2));
	}
	return 0; 
} 
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<queue>
using namespace std;
int vis[10][10];
int go[8][2] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
struct node
{
    int x,y;
    int count;
   
};
int bfs(int a,int b,int c,int d){
	
	queue<node> Q;
    node now,nex;
    now.x = a;
	now.y = b;
    now.count = 0;
    vis[now.x][now.y] = 1;
    Q.push(now);
    while(!Q.empty()){
    	nex=Q.front();
    	Q.pop();
		if(nex.x==c&&nex.y==d) return nex.count;
		for(int i=0;i<8;i++)
		{
			if(nex.x+go[i][0]>0&&nex.x+go[i][0]<=8&&nex.y+go[i][1]>0&&nex.y+go[i][1]<=8)
			{
				if(vis[nex.x+go[i][0]][nex.y+go[i][1]]==0){
					now.x=nex.x+go[i][0];
					now.y=nex.y+go[i][1];
					now.count=nex.count+1;
					vis[now.x][now.y]=1;
					Q.push(now);
				}
			}
		}
	}
	return -1;
}
int main(){
	char s1[2],s2[2];
	while(scanf("%s %s",&s1,&s2)!=EOF){
		int y1=s1[0]-'a'+1;
		int x1=s1[1]-48;
		int y2=s2[0]-'a'+1;
		int x2=s2[1]-48;
		for(int i=0;i<10;i++) 
			for(int j=0;j<10;j++) vis[i][j]=0;
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs(x1,y1,x2,y2));
	}
	return 0; 
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
