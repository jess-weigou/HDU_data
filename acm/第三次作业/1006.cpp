#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
} 
int main()
{
	int t,shuzu[1000];
	scanf("%d",&t);
	int p;
	while(t--)
	{
		p=1;
		int a,sum;
		sum=0;
		scanf("%d",&a);
		memset(shuzu,0,sizeof(shuzu));
		for(int i=0;i<a;i++)
		{
			scanf("%d",&shuzu[i]);
			sum	+=shuzu[i];
		} 
	
		if(sum % 2!=0)//如果不为偶数就一定不算 
		{
			printf("no\n"); 
		}else{
		for(int i=0;i<a;i++)
		{
			qsort(shuzu,a,sizeof(shuzu[0]),cmp);
			
//			for(int k=0;k<a;k++)
//			{
//				printf("shuzu : %d",shuzu[k]);	
//			} 
//			printf("\n");
			if(shuzu[0]==0)
			{
				break;
				p=1;
			}
			for(int k=0;k<shuzu[0];k++)
			{
				shuzu[k+1]-=1;
				if(shuzu[k+1]<0)
				{
					p=2;
					break;
				} 
			} 
			shuzu[0]=0;
	
		}
		if(p==1) printf("yes\n");
		else printf("no\n");	
		}
	}
} 
