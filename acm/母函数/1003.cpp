<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int number[250001];
int score[250001],c1[250001],c2[250001];
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		int sum=0;
		for(int i=1;i<=n;i++){
		 scanf("%d%d",&score[i],&number[i]);
		 sum+=number[i]*score[i];
		} 
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<=number[1]*score[1];i+=score[1]){
			c1[i]=1;
		} 
		int len=number[1]*score[1];
		for(int i=2;i<=n;i++)
		{
			len+=number[i]*score[i];
			for(int j=0;j<=len-number[i]*score[i];j++)
			{
				for(int k=0;k+j<=len&&k<=score[i]*number[i];k+=score[i])
				{
					c2[j+k]+=c1[j]; 
				}
			}
			for(int p=0;p<=len;p++)
			{
				c1[p]=c2[p];
				c2[p]=0;
			} 
		}
		for(int i=sum/2;i<=sum;i++)
		{
			if(c1[i]!=0){
				printf("%d %d\n",i,sum-i);
				break;
			}
		}
	} 
}
=======
#include<stdio.h>
#include<string.h>
int number[250001];
int score[250001],c1[250001],c2[250001];
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		int sum=0;
		for(int i=1;i<=n;i++){
		 scanf("%d%d",&score[i],&number[i]);
		 sum+=number[i]*score[i];
		} 
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<=number[1]*score[1];i+=score[1]){
			c1[i]=1;
		} 
		int len=number[1]*score[1];
		for(int i=2;i<=n;i++)
		{
			len+=number[i]*score[i];
			for(int j=0;j<=len-number[i]*score[i];j++)
			{
				for(int k=0;k+j<=len&&k<=score[i]*number[i];k+=score[i])
				{
					c2[j+k]+=c1[j]; 
				}
			}
			for(int p=0;p<=len;p++)
			{
				c1[p]=c2[p];
				c2[p]=0;
			} 
		}
		for(int i=sum/2;i<=sum;i++)
		{
			if(c1[i]!=0){
				printf("%d %d\n",i,sum-i);
				break;
			}
		}
	} 
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
