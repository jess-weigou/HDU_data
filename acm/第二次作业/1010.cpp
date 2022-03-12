<<<<<<< HEAD
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
=======
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
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
