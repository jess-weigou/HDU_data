#include<stdio.h>
#include<math.h>
int main()
{
	int n,a;
	long long int f;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		f=pow(2,a+1)+a-3;
		printf("%lld\n",f);
	}
} 
