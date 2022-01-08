#include<stdio.h>
#include<string.h>
int main()
{
	int a,n;
	int first=1,t_st=1,last;
	int k=1;
	int shuzu[100002];
	long int sum=0,max=0;
	scanf("%d",&n);
	while(n--)
	{
		max=-111111;
		sum=0;
		t_st=1;
		memset(shuzu,0,sizeof(shuzu));
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			scanf("%d",&shuzu[i]);
			sum+=shuzu[i];
			if(max<sum)
			{
				max=sum;
				last=i;
				first=t_st;
			} 
			if(sum<0)
			{
				sum=0;
				t_st=i+1;
			
			} 
		
		}
		printf("Case %d:\n",k);
		k++;
		printf("%ld %d %d\n",max,first,last);
		if(n!=0) printf("\n");
	}
	return 0;
} 
