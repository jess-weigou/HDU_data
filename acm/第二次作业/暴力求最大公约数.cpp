<<<<<<< HEAD
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
=======
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
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
