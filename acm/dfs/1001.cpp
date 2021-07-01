#include<stdio.h>
int number[1001]; 
int swap,cnt=0;
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		number[i]=i;
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
		cnt--;
		number[fn]=fm;
	}
}
int main()
{
	int n;
	int aa,bb;
	scanf("%d",&n);
	while(n--)
	{
		int i=1;
		scanf("%d %d ",&aa,&bb);
		init(aa);
		cnt=aa;
		for(i=1;i<=bb;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",cnt);
	}
}
