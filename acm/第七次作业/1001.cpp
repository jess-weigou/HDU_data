#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int vis[201];//是否访问 
int k[205];//上或者下几层 
typedef struct pos{
	int level;
	int steps;
}pos;
typedef struct quene{
	int level;
	int steps;
	struct quene *next;
}quene,*queneptr;
typedef struct link{
	queneptr front;//队头指针
	queneptr rear;//队尾指针 
}link;
void init(link *s)
{
	s->rear=s->front=(queneptr)malloc(sizeof(quene));
	s->front->next=NULL;
}
void push(link *s,int level,int steps)
{
	queneptr p=(queneptr)malloc(sizeof(quene));
	p->level=level;
	p->steps=steps;
	p->next=NULL;
	s->rear->next=NULL;
	s->rear->next=p;
	s->rear=p;
}
void pop(link *s,int &l,int &st)
{
	queneptr p=s->front->next;
	l=p->level;
	st=p->steps;
	s->front->next=p->next;
	if(s->rear==p) s->rear=s->front;
	free(p);
}
int bfs(int a,int b,int n)
{
	int l,st;
	link *s;
	s=(link*)malloc(sizeof(link));
	init(s);
	pos cur,nex;
	cur.level=a;
	cur.steps=0;
	push(s,cur.level,cur.steps);
	vis[a]=1;
	while(s->front!=s->rear)
	{
		pop(s,l,st);
		cur.level=l;
		cur.steps=st;
		nex.level=cur.level+k[cur.level];
		nex.steps=cur.steps+1;
		if(cur.level==b){
			return cur.steps;
		}
		if(nex.level<=n&&vis[nex.level]==0)
		{
			vis[nex.level]=1;
			push(s,nex.level,nex.steps);
		}
		nex.level=cur.level-k[cur.level];
		nex.steps=cur.steps+1;
		if(nex.level>=1&&vis[nex.level]==0)
		{
			vis[nex.level]=1;
			push(s,nex.level,nex.steps);
		}
	}
	return -1;
}
int main(){
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&a,&b);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
		}
		printf("%d\n",bfs(a,b,n));
	}
	return 0;
} 
