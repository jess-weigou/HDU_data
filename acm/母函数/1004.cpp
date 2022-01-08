#include<stdio.h>
#include<string.h>
int number[2001];
int score[2001],c1[2001],c2[2001];
int main()
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++) scanf("%d%d",&score[i],&number[i]);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		c1[0]=1;
		for(int i=1;i<=number[1];i++){
			c1[i*score[1]]=1;
		} 
		int len=number[1]*score[1];
		for(int i=2;i<=b;i++)
		{
			len+=number[i]*score[i];
			for(int j=0;j<=len-number[i]*score[i];j++)
			{
				for(int k=0;k+j<=a&&k<=score[i]*number[i];k+=score[i])
				{
					c2[j+k]+=c1[j]; 
				}
			}
			for(int p=0;p<=len&&p<=a;p++)
			{
				c1[p]=c2[p];
				c2[p]=0;
			} 
		}
		printf("%d\n",c1[a]);
	} 
}
