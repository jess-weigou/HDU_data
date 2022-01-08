#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	float sum,m;
	while(scanf("%f%d",&m,&n)!=EOF)
	{
		sum=m;
		for(i=1;i<n;i++)
		{
			sum+=sqrt(m);
			m=sqrt(m); 
		}
		printf("%.2f\n",sum);
	}
} 
