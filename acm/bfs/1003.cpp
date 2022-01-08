#include<stdio.h>
#include<math.h>
#include<string.h>
int vis[21];
int a[21],n,k;
int prime(int n)
{
	if(n==1||n==2) return 0;
	
	int a=sqrt(n);
	for(int i=2;i<=a;i++){
		if(n%i==0) return 0; 
	}
	return 1;
}
void bfs(int s)
{
	if(s==n&&prime(a[n]+1))
	{
		for(int i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",a[i]);
			else printf("%d ",a[i]);
		}
	}else{
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0&&prime(a[s]+i)==1)
		{
			vis[i]=1;
			a[s+1]=i;
			bfs(s+1);
			vis[i]=0;    //ÎªÁË»ØËÝ 
		}
	}
	}
}
int main()
{
	k=0;
	while(scanf("%d",&n)!=EOF)
	{
		k++;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		vis[1]=1;
		a[1]=1;
		printf("Case %d:\n",k);
		bfs(1);
		printf("\n");
	}
} 
