#include <stdio.h>
#include <stdlib.h>
long int shuzu[2001][1001];
int cmp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
} 
int func(int i,int j)
{
	if(j==0) return 0;
	if(j  *2> i) return 1000000000;
	return shuzu[i][j];
}
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{

	long int a[2001];
	int n;
	int k;
	while(scanf("%d %d",&n,&k)!=EOF)
		{
	
		for(int i=1;i<=n;i++) scanf("%ld",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				shuzu[i][j]=min(func(i-1,j),func(i-2,j-1)+(a[i]-a[i-1])*(a[i]-a[i-1]));
			}
		} 
		printf("%ld\n",shuzu[n][k]);
		}
		return 0;
} 

