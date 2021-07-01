#include<stdio.h>
#include<string.h>
int number[2001];
int score[2001],c1[2001],c2[2001];
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int sum=0;
		for(int i=1;i<=n;i++){
		 scanf("%d%d",&score[i],&number[i]);
		 sum+=number[i]*score[i];
		} 
		if(sum %3!=0){
			printf("sorry\n");
			continue;
		} 
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<=number[1]*score[1];i+=score[1]){
			c1[i]=1;
		} 
		sum=sum/3;
		int len=number[1]*score[1];
		for(int i=2;i<=n;i++)
		{
			len+=number[i]*score[i];
			for(int j=0;j<=len-number[i]*score[i];j++)
			{
				for(int k=0;k+j<=sum&&k<=score[i]*number[i];k+=score[i])
				{
					c2[j+k]+=c1[j]%10000; 
				}
			}
			for(int p=0;p<=len&&p<=sum;p++)
			{
				c1[p]=c2[p]%10000;
				c2[p]=0;
			} 
		}
		if(c1[sum/3]==0) printf("sorry\n");
		else printf("%d\n",c1[sum]);
	} 
}
