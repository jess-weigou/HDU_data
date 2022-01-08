#include<stdio.h>
#include<string.h>
#include<math.h>
#define mod 99983
int main()
{
	int n,c[mod+1],k;
	char num[200],num1[200],temp[200];
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",num);
			int tmp=0;
			int len=strlen(num);
			for(int j=0;j<len;j++)
			{
				tmp=(tmp*13+num[j]-'0') % mod;
			}
			if(++c[tmp]>ans) ans=c[tmp];
		}
		printf("%d\n",ans);	
	}
	return 0;
} 
