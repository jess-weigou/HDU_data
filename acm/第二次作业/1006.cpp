#include<stdio.h>
int main(){
	int a;
	int c,d;
	int i,j,max,sum;
	scanf("%d",&a);//a代表有几组 
	int number[a];
	for( i=0;i<a;i++)
	{
		scanf("%d",&number[i]);
		scanf("%d",&max);//输入第一个数 
		sum=max;
		for(j=1;j<number[i];j++)
		{
			scanf("%d",&c);
			sum+=c;
			if(c>max) max=c;
		}
		sum=sum-max;
		if(max<=sum+1) printf("Yes\n");
		else printf("No\n");	
	}
} 

