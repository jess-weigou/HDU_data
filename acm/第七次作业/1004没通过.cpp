<<<<<<< HEAD
/*这题不能ac，我知道原因了，因为天使也有可能再遇到，就是绕个圈重新遇到天使*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int vis[211][211];
int start1,start2;
struct node
{
	int a,b,number;
	bool friend operator<(node a,node b)
	{
	return a.number>b.number;
	}
};
int bfs(int a,int b){
	queue<node>q;
	node cur,next;
	cur.number=0;
	cur.a=start1;
	cur.b=start2;
	q.push(cur);
	vis[start1][start2]=1;
	while(!q.empty())
	{
		next=q.front();
		q.pop();
		if(next.b+1<=b&&(vis[next.a][next.b+1]==0||vis[next.a][next.b+1]==2))//b+1
		{
			cur.number=next.number+(vis[next.a][next.b+1]*0.5+1);
			cur.a=next.a;
			cur.b=next.b+1;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		}else if(next.b+1<=b&&vis[next.a][next.b+1]==3){
			cur.number=next.number+1;
			return cur.number;
		}
		if(next.b-1>=1&&(vis[next.a][next.b-1]==0||vis[next.a][next.b-1]==2))//b-1
		{
			cur.number=next.number+(vis[next.a][next.b-1]*0.5+1);
			cur.a=next.a;
			cur.b=next.b-1;
			vis[cur.a][cur.b]=1;
			q.push(cur);

		}else if(next.b-1>=1&&vis[next.a][next.b-1]==3){
			cur.number=next.number+1;
			return cur.number; 
		}
		if(next.a+1<=a&&(vis[next.a+1][next.b]==0||vis[next.a+1][next.b]==2))//a+1
		{
			cur.number=next.number+(vis[next.a+1][next.b]*0.5+1);
			cur.a=next.a+1;
			cur.b=next.b;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		
		}else if(next.a+1<=a&&vis[next.a+1][next.b]==3){
			cur.number=next.number+1;
			return cur.number; 
		}
		if(next.a-1>=1&&(vis[next.a-1][next.b]==0||vis[next.a-1][next.b]==2))//a-1
		{
			cur.number=next.number+(vis[next.a-1][next.b]*0.5+1);
			cur.a=next.a-1;
			cur.b=next.b;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		
		}else if(next.a-1>=1&&vis[next.a-1][next.b]==3){
			cur.number=next.number+1;
			return cur.number;
		}
		
	}
	return -1;
}
int main()
{
	int a,b;
	char c;
	while(scanf("%d %d\n",&a,&b)!=EOF) {
	for(int i=0;i<210;i++)
		for(int j=0;j<210;j++) vis[i][j]=0;	
	for(int i=1;i<=a;i++){      //输入 
		for(int j=1;j<=b;j++){
			if(j==b){
				if(i==a) scanf("%c",&c);
				else scanf("%c\n",&c);
			} 
			else scanf("%c",&c);
			if(c=='#') vis[i][j]=1;
			else if(c=='.') vis[i][j]=0; 
			else if(c=='r'){
				vis[i][j]=3;
			}else if(c=='a'){
				start1=i;
				start2=j;
			}else if(c=='x') vis[i][j]=2;
		}
		
	}
	int k=bfs(a,b);
	if(k!=-1) printf("%d\n",k);
	else printf("Poor ANGEL has to stay in the prison all his life.\n");
}
} 
=======
/*这题不能ac，我知道原因了，因为天使也有可能再遇到，就是绕个圈重新遇到天使*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int vis[211][211];
int start1,start2;
struct node
{
	int a,b,number;
	bool friend operator<(node a,node b)
	{
	return a.number>b.number;
	}
};
int bfs(int a,int b){
	queue<node>q;
	node cur,next;
	cur.number=0;
	cur.a=start1;
	cur.b=start2;
	q.push(cur);
	vis[start1][start2]=1;
	while(!q.empty())
	{
		next=q.front();
		q.pop();
		if(next.b+1<=b&&(vis[next.a][next.b+1]==0||vis[next.a][next.b+1]==2))//b+1
		{
			cur.number=next.number+(vis[next.a][next.b+1]*0.5+1);
			cur.a=next.a;
			cur.b=next.b+1;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		}else if(next.b+1<=b&&vis[next.a][next.b+1]==3){
			cur.number=next.number+1;
			return cur.number;
		}
		if(next.b-1>=1&&(vis[next.a][next.b-1]==0||vis[next.a][next.b-1]==2))//b-1
		{
			cur.number=next.number+(vis[next.a][next.b-1]*0.5+1);
			cur.a=next.a;
			cur.b=next.b-1;
			vis[cur.a][cur.b]=1;
			q.push(cur);

		}else if(next.b-1>=1&&vis[next.a][next.b-1]==3){
			cur.number=next.number+1;
			return cur.number; 
		}
		if(next.a+1<=a&&(vis[next.a+1][next.b]==0||vis[next.a+1][next.b]==2))//a+1
		{
			cur.number=next.number+(vis[next.a+1][next.b]*0.5+1);
			cur.a=next.a+1;
			cur.b=next.b;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		
		}else if(next.a+1<=a&&vis[next.a+1][next.b]==3){
			cur.number=next.number+1;
			return cur.number; 
		}
		if(next.a-1>=1&&(vis[next.a-1][next.b]==0||vis[next.a-1][next.b]==2))//a-1
		{
			cur.number=next.number+(vis[next.a-1][next.b]*0.5+1);
			cur.a=next.a-1;
			cur.b=next.b;
			vis[cur.a][cur.b]=1;
			q.push(cur);
		
		}else if(next.a-1>=1&&vis[next.a-1][next.b]==3){
			cur.number=next.number+1;
			return cur.number;
		}
		
	}
	return -1;
}
int main()
{
	int a,b;
	char c;
	while(scanf("%d %d\n",&a,&b)!=EOF) {
	for(int i=0;i<210;i++)
		for(int j=0;j<210;j++) vis[i][j]=0;	
	for(int i=1;i<=a;i++){      //输入 
		for(int j=1;j<=b;j++){
			if(j==b){
				if(i==a) scanf("%c",&c);
				else scanf("%c\n",&c);
			} 
			else scanf("%c",&c);
			if(c=='#') vis[i][j]=1;
			else if(c=='.') vis[i][j]=0; 
			else if(c=='r'){
				vis[i][j]=3;
			}else if(c=='a'){
				start1=i;
				start2=j;
			}else if(c=='x') vis[i][j]=2;
		}
		
	}
	int k=bfs(a,b);
	if(k!=-1) printf("%d\n",k);
	else printf("Poor ANGEL has to stay in the prison all his life.\n");
}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
