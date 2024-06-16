<<<<<<< HEAD
#include<stdio.h>
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m % (n+1)==0)
		{
			printf("none\n");
			continue;
		}
		if(m<=n)
		{
			for(int i=m;i<=n;i++)
			{
				if(i==m) printf("%d",i);
				else printf(" %d",i);
			}
			printf("\n");
		}else{
			printf("%d\n",m%(n+1));
		}
	}
}
=======
#include<stdio.h>
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m % (n+1)==0)
		{
			printf("none\n");
			continue;
		}
		if(m<=n)
		{
			for(int i=m;i<=n;i++)
			{
				if(i==m) printf("%d",i);
				else printf(" %d",i);
			}
			printf("\n");
		}else{
			printf("%d\n",m%(n+1));
		}
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
