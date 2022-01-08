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
