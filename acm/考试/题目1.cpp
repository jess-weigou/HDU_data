#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	int sum1,sum2,sum3;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		sum1=a*a;
		sum2=b*c;
		sum3=d*e/2;
		if(sum1>sum2&&sum1>sum3) printf("Perch\n");
		else if(sum2>sum1&&sum2>sum3) printf("Semon\n");
		else printf("Belinda\n");
		
	}
} 
