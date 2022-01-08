#include<stdio.h>
#include<string.h>
int shuzu[51];
int sum[51];
void ditui()
{
	memset(shuzu,0,sizeof(shuzu));
	memset(sum,0,sizeof(sum));
	shuzu[1]=1;
	shuzu[2]=0;
	shuzu[3]=4;
	shuzu[4]=4;
	sum[1]=1;
	sum[2]=1;
	sum[3]=5;
	sum[4]=9;
	for(int i=5;i<51;i++)
	{
		shuzu[i]=4*shuzu[i-3]+4*shuzu[i-2]+4*shuzu[i-4];
		sum[i]=sum[i-1]+shuzu[i]-shuzu[i-5];
	}
}
int main()
{
	int n,a;
	scanf("%d",&n);
	ditui();
	while(n--)
	{
		scanf("%d",&a);
		printf("%d\n",sum[a]);
	}
}
