#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		int *hash=new int[2000003];
		int count=0;
		if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0)
		{
			printf("0\n");
			continue; 
		} 


		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				hash[a*i*i+b*j*j+1000000]++; 
			}
		} 
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				count+=hash[-(c*i*i+d*j*j)+1000000]; 
			}
		} 
		printf("%d\n",count*16);
		delete [] hash;
	}
} 
