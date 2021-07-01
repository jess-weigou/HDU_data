#include<stdio.h>
int main(){
	int a,b,sum;
	int i=1;
	while(scanf("%d %d",&a,&b)!=EOF){
		sum=a;
		while(sum %b!=0)
		{
			i++;
			sum=a*i;
		}
	printf("%d\n",sum);
	i=1;
	}
	
} 
