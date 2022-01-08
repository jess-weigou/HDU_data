<<<<<<< HEAD
#include<stdio.h>
int LCM(int a,int b)
{
	int c;
	while(a %b!=0)
	{
		c= a % b;
		a=b;
		b=c;
	}
	return b;
}
 int main()
 {
 	int a,i,number1,number2,b,j;
 	long sum;
 	scanf("%d",&a);
 	for(i=0;i<a;i++)
	 {
	 	scanf("%d",&b);
	 	scanf("%d",&sum);
	 	for(j=1;j<b;j++)
		 {
		 	scanf("%d",&number1);
	 		sum=sum/LCM(sum,number1)*number1;
		 }
	 	printf("%d\n",sum);
	 }
 }
=======
#include<stdio.h>
int LCM(int a,int b)
{
	int c;
	while(a %b!=0)
	{
		c= a % b;
		a=b;
		b=c;
	}
	return b;
}
 int main()
 {
 	int a,i,number1,number2,b,j;
 	long sum;
 	scanf("%d",&a);
 	for(i=0;i<a;i++)
	 {
	 	scanf("%d",&b);
	 	scanf("%d",&sum);
	 	for(j=1;j<b;j++)
		 {
		 	scanf("%d",&number1);
	 		sum=sum/LCM(sum,number1)*number1;
		 }
	 	printf("%d\n",sum);
	 }
 }
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
