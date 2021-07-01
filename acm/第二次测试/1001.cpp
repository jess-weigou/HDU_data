#include<stdio.h>
int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n==0) break;
		int n1=1,n2=1,n3=1,n4=1;
		while(n %2==0){
			n1++;
			n=n/2;
		}
				while(n %3==0){
			n2++;
			n=n/3;
		}
				while(n %5==0){
			n3++;
			n=n/5;
		}
				while(n %7==0){
			n4++;
			n=n/7;
		}
		printf("%lld\n",n1*n2*n3*n4);
	}
}
