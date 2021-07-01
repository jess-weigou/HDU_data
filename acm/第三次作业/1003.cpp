#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct times{
	int time;
	int score;
}; 
int cmp(const void *a,const void *b)
{
	struct times *c=(times *)a;
	struct times *d=(times *)b;
	return d->score-c->score;
	
}
int main()
{
	int n,a,sum;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%d",&a);
		int wancheng[10000];
		for(int k=0;k<10000;k++)
		{
			wancheng[k]=0;
		}
		struct times shabi[a];
		for(int i=0;i<a;++i)
		{
			scanf("%d",&shabi[i].time);
		}
		for(int i=0;i<a;++i)
		{
			scanf("%d",&shabi[i].score);
		}
		qsort(shabi,a,sizeof(shabi[0]),cmp);
		for(int i=0;i<a;i++)
		{
			int j=shabi[i].time;
			for(;j>0;--j)
			{
				if(wancheng[j]==0)
				{
					wancheng[j]=1;
					break;
				}
			}
			if(j==0) sum+=shabi[i].score;
			
		} 
		printf("%d\n",sum);
	}	
	return 0;
} 
