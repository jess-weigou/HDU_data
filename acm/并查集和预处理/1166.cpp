#include<stdio.h>
#include<string.h>
int number[50001];
int tnumber[50005];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int y,int n)
{
	while(x<=n)
	{
		tnumber[x]+=y;
		x+=lowbit(x);
	} 
}
void sub(int x,int y,int n)
{
	while(x<=n)
	{
			tnumber[x]-=y;
			x+=lowbit(x);
	} 
}
int query(int x,int y,int n)
{
	int sum1=0,sum2=0;
	x=x-1;
	while(x>0)
	{
		sum1+=tnumber[x];
		x-=lowbit(x);
	}
	while(y>0)
	{
		sum2+=tnumber[y];
		y-=lowbit(y);
	}
	
	return sum2-sum1;
		
}
int main()
{
	int n,a,b,d;
	char c[8];
	scanf("%d",&n);
	int k=1;
	while(n--)
	{
		memset(number,0,sizeof(number));
		memset(tnumber,0,sizeof(tnumber));
		scanf("%d",&a);
		for(int i=1;i<=a;i++)//ÊäÈëÈËÊı 
		{
			scanf("%d",&number[i]);
			add(i,number[i],a);
		} 
		printf("Case %d:\n",k++);
		while(1)
		{
			scanf("%s",c);
			if(c[0]=='E') break;
			scanf("%d%d",&b,&d);
			if(c[0]=='Q')
			{
				printf("%d\n",query(b,d,a));
			}else if(c[0]=='A')
			{
				add(b,d,a);
			}else if(c[0]=='S')
			{
				sub(b,d,a);
			}
		}
	} 
	return 0; 
} 
