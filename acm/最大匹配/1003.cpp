#include<stdio.h>
#include<string.h>
#define N 501
int link[N][N],used[N],boy[N];
int count,n;
bool find(int n1)
{
	for(int i=1;i<=n;i++)
	{
		if(link[n1][i]==1&&!used[i])
		{
			used[i]=true;
			if(!boy[i]||find(boy[i]))
			{
				boy[i]=n1;
				return true;
			}
			
		}
	}
	return false;
}
int main()
{
	int c,d;
	char l1,l2,l3,l4,l5;
	int a1,a2,a3;
	 
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		memset(link,0,sizeof(link));
		memset(boy,0,sizeof(boy));
		for(int i=1;i<=n;i++)
		{
			scanf("%d: (%d)",&a1,&a2);
			for(int k=1;k<=a2;k++)
			{
				scanf("%d",&a3);
				link[a1+1][a3+1]=1;
			}	
		} 
		for(int i=1;i<=n;i++)
		{
			memset(used,false,sizeof(used)); 
			if(find(i))
			{
				count++;
			} 
		}	
		printf("%d\n",n-count/2);
	}
} 
