#include<stdio.h>
#include<string.h>
#include<math.h>
int c1[10001],c2[10001];
int number[10001];
int number1[10001];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<n;i++)  scanf("%d",&number[i]);
		c1[number[0]]=1; 
		c1[0]=1;
		int len=number[0];
		for(int i=1;i<n;i++)
		{
			len+=number[i];
			for(int j=0;j<=len-number[i];j++)
			{
				for(int k=0;k<=number[i];k+=number[i])
				{
					c2[j+k]+=c1[j]; 
					c2[abs(j-k)]+=c1[j];
				}
			}
			for(int p=0;p<=len;p++)
			{
				c1[p]=c2[p];
				c2[p]=0;
			} 
		}
		int ans=0;
		for(int i=1;i<=len;i++)
		{
			if(!c1[i])
			{
				ans++;
			} 
		} 
		if(ans==0) printf("%d\n",ans);
		else {
			printf("%d\n",ans);
			int k=0;
			for(int i=1;i<len;i++)
			{
				if(!c1[i])
				{
					k++;
					if(k==1) printf("%d",i);
					else printf(" %d",i);
					
				} 
			} 
			printf("\n");
		}
	}
	return 0;
} 
