#include<stdio.h>
#include<string.h>
int f[1001];
int hash[1001];
int sg[1001];
void getsg(int n)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(hash,0,sizeof(hash));
		for(int j=1;f[j]<=i;j++)
		{
			hash[sg[i-f[j]]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(hash[j]==0)
			{
				sg[i]=j;
				break;
			}
		}
	}
}
int main()
{
	int a,b,c;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=16;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	getsg(1000);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(a==0&&b==0&&c==0) break;
		if((sg[a]^sg[b]^sg[c])==0)
		{
			printf("Nacci\n");
		}else {
			
			printf("Fibo\n");
		}
	}
	return 0;
}
