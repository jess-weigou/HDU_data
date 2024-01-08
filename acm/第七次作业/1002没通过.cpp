<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int visit[102][102];
struct node
{
int a,b,number;
	friend bool operator<(node a,node b)
	{
	return a.number>b.number;
	}
};
int bfs(int a,int b,int c)
{
queue<node>q;
node cur,next;
cur.number=0;
cur.a=a;
cur.b=0;
q.push(cur);
visit[a][0]=1;
while(!q.empty())
{
	next=q.front();
	q.pop();
	if(next.a==a/2&&next.b==a/2)
	return next.number;
	if(next.a-c>=0&&visit[next.a-c][next.b]==0&&a-next.a-next.b<c)//a倒到c&&c没满 
	{
		cur.number=next.number+1;
		cur.a=next.a-c;
		cur.b=next.b;
		q.push(cur);
		visit[next.a-c][next.b]=1;
	}
	if(next.a-b+next.b>=0&&visit[next.a-b+next.b][b]==0&&next.b<b)//a倒到b b没满 
	{
		cur.number=next.number+1;
		cur.a=next.a-b+next.b;
		cur.b=b;
		q.push(cur);
		visit[cur.a][b]=1;
	}
	if(next.b-c>=0&&visit[next.a][next.b-c]==0&&a-next.a-next.b<c) //b倒到c &&c没满 
	{
		cur.number=next.number+1;
		cur.a=next.a;
		cur.b=next.b-c;
		q.push(cur);
		visit[next.a][next.b-c]=1;
	}
	if(next.a+next.b<=a&&next.b>0&&visit[next.a+next.b][0]==0)//b向a倒 
	{
		cur.number=next.number+1;
		cur.a=next.a+next.b;
		cur.b=0;
		q.push(cur);
		visit[next.a+next.b][0]=1; 
	}
	if(a-next.a-next.b>0&&a-next.a<=b&&visit[next.a][a-next.a]==0&&next.b+c<=b)//c倒到b&&b没满 
	{
		cur.number=next.number+1;
		cur.a=next.a;
		cur.b=a-next.a;
		q.push(cur);
		visit[next.a][a-next.a]=1;
	}
	if(a-next.a-next.b>0&&visit[a-next.b][next.b]==0)//c向a倒 
	{
		cur.number=next.number+1;
		cur.a=a-next.b;
		cur.b=next.b;
		q.push(cur);
		visit[a-next.b][next.b]=1; 
	}
}
return -1;
}
int main()
{
	int swap;
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		for(int i=0;i<102;i++)
		{
			for(int j=0;j<102;j++){
				visit[i][j]=0;
			}
		} 
		if(a==0&&c==0&&b==0){
			break;
		} 
		
		if(a %2==1)
		{
			printf("NO\n");
			continue;
		} else{
		if(b<c){
		swap=b;
		b=c;
		c=swap;
		}
			int k=bfs(a,b,c);
			if(k==-1) printf("NO\n");
			else printf("%d\n",k);
		}
	} 
} 
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int visit[102][102];
struct node
{
int a,b,number;
	friend bool operator<(node a,node b)
	{
	return a.number>b.number;
	}
};
int bfs(int a,int b,int c)
{
queue<node>q;
node cur,next;
cur.number=0;
cur.a=a;
cur.b=0;
q.push(cur);
visit[a][0]=1;
while(!q.empty())
{
	next=q.front();
	q.pop();
	if(next.a==a/2&&next.b==a/2)
	return next.number;
	if(next.a-c>=0&&visit[next.a-c][next.b]==0&&a-next.a-next.b<c)//a倒到c&&c没满 
	{
		cur.number=next.number+1;
		cur.a=next.a-c;
		cur.b=next.b;
		q.push(cur);
		visit[next.a-c][next.b]=1;
	}
	if(next.a-b+next.b>=0&&visit[next.a-b+next.b][b]==0&&next.b<b)//a倒到b b没满 
	{
		cur.number=next.number+1;
		cur.a=next.a-b+next.b;
		cur.b=b;
		q.push(cur);
		visit[cur.a][b]=1;
	}
	if(next.b-c>=0&&visit[next.a][next.b-c]==0&&a-next.a-next.b<c) //b倒到c &&c没满 
	{
		cur.number=next.number+1;
		cur.a=next.a;
		cur.b=next.b-c;
		q.push(cur);
		visit[next.a][next.b-c]=1;
	}
	if(next.a+next.b<=a&&next.b>0&&visit[next.a+next.b][0]==0)//b向a倒 
	{
		cur.number=next.number+1;
		cur.a=next.a+next.b;
		cur.b=0;
		q.push(cur);
		visit[next.a+next.b][0]=1; 
	}
	if(a-next.a-next.b>0&&a-next.a<=b&&visit[next.a][a-next.a]==0&&next.b+c<=b)//c倒到b&&b没满 
	{
		cur.number=next.number+1;
		cur.a=next.a;
		cur.b=a-next.a;
		q.push(cur);
		visit[next.a][a-next.a]=1;
	}
	if(a-next.a-next.b>0&&visit[a-next.b][next.b]==0)//c向a倒 
	{
		cur.number=next.number+1;
		cur.a=a-next.b;
		cur.b=next.b;
		q.push(cur);
		visit[a-next.b][next.b]=1; 
	}
}
return -1;
}
int main()
{
	int swap;
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		for(int i=0;i<102;i++)
		{
			for(int j=0;j<102;j++){
				visit[i][j]=0;
			}
		} 
		if(a==0&&c==0&&b==0){
			break;
		} 
		
		if(a %2==1)
		{
			printf("NO\n");
			continue;
		} else{
		if(b<c){
		swap=b;
		b=c;
		c=swap;
		}
			int k=bfs(a,b,c);
			if(k==-1) printf("NO\n");
			else printf("%d\n",k);
		}
	} 
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
