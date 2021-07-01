#include<stdio.h>
#include<algorithm>
using namespace std;
int number[101];
struct node{
	int a,b,c;
}s[10001];
int find(int x){
	while(x!=number[x]){
		x=number[x];
	}
	return x;
}
bool cmp(node x,node y)
{
	return x.c<y.c;
}
void init(){
	for(int i=0;i<=100;i++) number[i]=i; 
}
int main()
{
	int n,c,p,a,b,t,sum,num;
	while(scanf("%d",&t)!=EOF)
	{
		init();
		p=0;
		sum=0;
		num=0;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=t;j++)
			{
				scanf("%d",&c);
				if(c!=0)
				{
					s[p].a=i;s[p].b=j;s[p].c=c;
					p++;
				}
			}
		}
		sort(s,s+p,cmp);
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&a,&b);
			while(find(a)!=find(b))
			{
				number[find(b)]=find(a);
				num++;
			}
		} 
		for(int i=0;i<p&&num<t-1;i++) 
		{
			if(find(s[i].a)!=find(s[i].b))
			{
				sum+=s[i].c;
				number[find(s[i].b)]=find(s[i].a);
			}
		} 
		printf("%d\n",sum);
	}
	
} 
