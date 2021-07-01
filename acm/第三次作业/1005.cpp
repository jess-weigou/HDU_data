#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
} 
int main()
{
	int n,i,win,lose;

	int shuzu1[1004];
	int shuzu2[1004];  
	while(scanf("%d",&n)!=EOF)
	{
		win=0;
		lose=0;
		if(n==0) break;
		int t_slow=0;
		int t_fast=n-1;
    	int k_slow=0;
		int k_fast=n-1;
		for( i=0;i<n;i++) scanf("%d",&shuzu1[i]);
		for( i=0;i<n;i++) scanf("%d",&shuzu2[i]);
		qsort(shuzu1,n,sizeof(shuzu1[0]),cmp);
		qsort(shuzu2,n,sizeof(shuzu2[0]),cmp);
		while(t_slow<=t_fast)
		{
			if(shuzu1[t_slow]>shuzu2[k_slow])
			{
				win++;
				t_slow++;
				k_slow++;
			}else if(shuzu1[t_slow]<shuzu2[k_slow])
			{
				lose++;
				t_slow++;
				k_fast--;
			}else
			{
				if(shuzu1[t_fast]>shuzu2[k_fast])
				{
					win++;
					t_fast--;
					k_fast--;
				}else if(shuzu1[t_fast]<shuzu2[k_fast])
				{
					lose++;
					t_slow++;
					k_fast--;
				}else
				{
					if(shuzu1[t_slow]<shuzu2[k_fast])
						lose++;
						t_slow++;
						k_fast--;
				}
			}
		}
		printf("%d\n",200*(win-lose));
	}
	return 0;
} 
