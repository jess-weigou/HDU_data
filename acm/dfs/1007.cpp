#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int from ;
	int to;
	int value;
}Node,*node; 
int find(int *father,int x)
{
	if(x!=father[x]) father[x]=find(father,father[x]);
	return father[x];
}
void merge(int *father,int from,int to)
{
	int a=find(father,from);
	int b=find(father,to);
	father[a]=b;
}
int cmp(const void *x,const void *y){
       Node xx = *(node)x;
       Node yy = *(node)y;
       return xx.value-yy.value;
  }
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		Node mp[n*n+1];
		int father[n+1];
		for(int i=0;i<=n;i++)//初始化 
		{
			father[i]=i;
		} 
		for(int i=0;i<n*(n-1)/2;i++)
		{
			scanf("%d%d%d",&mp[i].from,&mp[i].to,&mp[i].value);
		}
		qsort(mp,n*(n-1)/2,sizeof(mp[0]),cmp);//从第一个开始排序 
		int sum=0;
		for(int i=0;i<n*(n-1)/2;i++)
		{
			if(find(father,mp[i].from)!=find(father,mp[i].to))
			{
				merge(father,mp[i].from,mp[i].to);
				sum+=mp[i].value;
			}
		}
		printf("%d\n",sum);
	}
}
