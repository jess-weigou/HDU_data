<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int c1[20001],c2[20001];
int value[30];
int main()
{
	int n,len;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=1;i<=26;i++) scanf("%d",&value[i]);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		len=value[1];
		for(int i=0;i<=value[1];i++) c1[i]=1;
		for(int i=2;i<=26;i++)
		{
			len+=value[i]*i;
			for(int j=0;j<=len-value[i]*i;j++)
			{
				for(int k=0;k<=value[i]*i;k+=i)
				{
					c2[k+j]+=c1[j];
					
				} 
			}
			for(int p=0;p<=len;p++){
				c1[p]=c2[p];
				c2[p]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=50;i++) ans+=c1[i];
		printf("%d\n",ans);
	}
}
=======
#include<stdio.h>
#include<string.h>
int c1[20001],c2[20001];
int value[30];
int main()
{
	int n,len;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=1;i<=26;i++) scanf("%d",&value[i]);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		len=value[1];
		for(int i=0;i<=value[1];i++) c1[i]=1;
		for(int i=2;i<=26;i++)
		{
			len+=value[i]*i;
			for(int j=0;j<=len-value[i]*i;j++)
			{
				for(int k=0;k<=value[i]*i;k+=i)
				{
					c2[k+j]+=c1[j];
					
				} 
			}
			for(int p=0;p<=len;p++){
				c1[p]=c2[p];
				c2[p]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=50;i++) ans+=c1[i];
		printf("%d\n",ans);
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
