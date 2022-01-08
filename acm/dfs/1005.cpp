#include<stdio.h>
#define max 1000000
int number[1000001]; 
int number1[1000001];
int swap;
int cnt=0;
int max1;
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		number[i]=i;
		number1[i]=1;
	}           
}
int findfather(int m)
{
	while(m!=number[m])
	{
		m=number[m];
	}
	return m;
}
void merge(int m,int n)
{
	int fm=findfather(m);
	int fn=findfather(n);
	if(fm>fn) {
		swap=fm;
		fm=fn;
		fn=swap;
	}
	if(fm!=fn)
	{
		number[fn]=fm;
		number1[fm]+=number1[fn];
		if(number1[fm]>max1) max1=number1[fm];
	}
}
int main()
{
	int n;
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		max1=1;
		init(max);
		for(int i=1;i<=n;i++)
		{
			
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",max1);
	}
}
