<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
} 
int main()
{
	int a,sum1,sum2;
	
	while(scanf("%d",&a)!=EOF)
	{
		sum1=0;
	sum2=0;
	if(a==0) break;
	int shuzu1[a],shuzu2[a];
	for(int i=0;i<a;i++)  scanf("%d",&shuzu1[i]);
	for(int i=0;i<a;i++)  scanf("%d",&shuzu2[i]);
	qsort(shuzu1,a,sizeof(shuzu1[0]),cmp);
	qsort(shuzu2,a,sizeof(shuzu2[0]),cmp);
//	for(int i=0;i<a;i++)
//	{
//		printf("sum1,sum2 %d %d\n",shuzu1[i],shuzu2[i]);
//	}
	for(int i=0;i<a;i++)
	{
		if(shuzu1[i]>shuzu2[i]) sum1+=2;
		else if(shuzu1[i]==shuzu2[i])
		{
			sum1++;
			sum2++;
		}
		else sum2+=2;
	}
	printf("%d vs %d\n",sum1,sum2);
	memset(shuzu1,0,sizeof(shuzu1));
	memset(shuzu2,0,sizeof(shuzu2));
	}
} 
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
} 
int main()
{
	int a,sum1,sum2;
	
	while(scanf("%d",&a)!=EOF)
	{
		sum1=0;
	sum2=0;
	if(a==0) break;
	int shuzu1[a],shuzu2[a];
	for(int i=0;i<a;i++)  scanf("%d",&shuzu1[i]);
	for(int i=0;i<a;i++)  scanf("%d",&shuzu2[i]);
	qsort(shuzu1,a,sizeof(shuzu1[0]),cmp);
	qsort(shuzu2,a,sizeof(shuzu2[0]),cmp);
//	for(int i=0;i<a;i++)
//	{
//		printf("sum1,sum2 %d %d\n",shuzu1[i],shuzu2[i]);
//	}
	for(int i=0;i<a;i++)
	{
		if(shuzu1[i]>shuzu2[i]) sum1+=2;
		else if(shuzu1[i]==shuzu2[i])
		{
			sum1++;
			sum2++;
		}
		else sum2+=2;
	}
	printf("%d vs %d\n",sum1,sum2);
	memset(shuzu1,0,sizeof(shuzu1));
	memset(shuzu2,0,sizeof(shuzu2));
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
