<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int a,b,i,c,d,j,sum,m;
	while(scanf("%d%d",&a,&b)&&(a!=0||b!=0))
	{
		
		sum=a;
		for(i=1;i<b;i++){
			sum=a*sum;
			if(sum>1000) sum=sum%1000;
		}
		printf("%d\n",sum);
	}

} 
=======
#include<stdio.h>
int main()
{
	int a,b,i,c,d,j,sum,m;
	while(scanf("%d%d",&a,&b)&&(a!=0||b!=0))
	{
		
		sum=a;
		for(i=1;i<b;i++){
			sum=a*sum;
			if(sum>1000) sum=sum%1000;
		}
		printf("%d\n",sum);
	}

} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
