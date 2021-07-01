#include<stdio.h>
#include<string.h>
int c1[100001],c2[100001];
int number[4];
int main()
{
	int n,sum,sum1;
	int number1[3]={1,2,5};
	while(scanf("%d%d%d",&number[0],&number[1],&number[2])!=EOF)
	{
		if(!number[0]&&!number[1]&&!number[2])  
			break;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<=number[0];i++)  c1[i]=1; 
		int len=number[0];
		for(int i=1;i<=2;i++)
		{
			len+=number[i]*number1[i];
			for(int j=0;j<=len-number[i]*number1[i];j++)
			{
				for(int k=0;k+j<=len;k+=number1[i])
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
		int i=0;
		while(c1[i]!=0){
			i++;
		}
		printf("%d\n",i);
	}
} 
