<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
 int number[1000005];
int main()
{
	int m,n,i,max;
	while(scanf("%d%d",&m,&n)!=EOF){
		max=0;
		memset(number,0,sizeof(number));
		for(int k=1;k<=m;k++)
		{
			scanf("%d",&i);
			number[i+500000]=1;
			if(max<i+500000) max=i+500000;
		}
		printf("%d",max-500000);
		n--;
		for(int j=max-1;j>=0&&n>0;j--)
		{
			if(number[j]!=0){
				printf(" %d",j-500000);
				n--;
			}
		}
		printf("\n");
	}
	return 0;
} 
=======
#include<stdio.h>
#include<string.h>
 int number[1000005];
int main()
{
	int m,n,i,max;
	while(scanf("%d%d",&m,&n)!=EOF){
		max=0;
		memset(number,0,sizeof(number));
		for(int k=1;k<=m;k++)
		{
			scanf("%d",&i);
			number[i+500000]=1;
			if(max<i+500000) max=i+500000;
		}
		printf("%d",max-500000);
		n--;
		for(int j=max-1;j>=0&&n>0;j--)
		{
			if(number[j]!=0){
				printf(" %d",j-500000);
				n--;
			}
		}
		printf("\n");
	}
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
