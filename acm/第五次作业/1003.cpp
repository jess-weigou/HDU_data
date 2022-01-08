#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct number{
	int n1;
	int n2;
}number[1002];
int main()
{
	int n,a;
	int max=0,max2=0;
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n==0) break;
		memset(&number,0,sizeof(number[0]));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			number[i].n1 =a;
			number[i].n2 =a;
			if(max<a) max=a;
		} 
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				
				if(number[i].n1>number[j].n1)
				{									
					if(max2<number[j].n2) max2=number[j].n2;
				}
			}
			number[i].n2+=max2;
			if(max<number[i].n2) max=number[i].n2;
			max2=0;
		}
		printf("%d\n",max);
		max=0;
	}
} 
