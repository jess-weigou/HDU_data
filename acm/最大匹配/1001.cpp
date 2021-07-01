#include<stdio.h>
#include<string.h>
#define N 800
int link[N][N],used[N],boy[N];
int count,a,b;
bool find(int n)
{
	for(int i=1;i<=b;i++)
	{
		if(link[n][i]==1&&!used[i])
		{
			used[i]=true;
			if(!boy[i]||find(boy[i]))
			{
				boy[i]=n;
				return true;
			}
			
		}
	}
	return false;
}
int main()
{
	int n,c,d;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		count=0;
		scanf("%d%d",&a,&b);
		memset(link,0,sizeof(link));
		memset(boy,0,sizeof(boy));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&c,&d);
			link[c][d]=1;	
		} 
		for(int i=1;i<=a;i++)
		{
			memset(used,false,sizeof(used)); 
			if(find(i))
			{
				count++;
			} 
		}	
		printf("%d\n",count);
	}
} 
