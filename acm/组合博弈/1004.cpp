<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int f[1001],number[1001],hash[1001],sg[1001];
void getsq(int n)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(hash,0,sizeof(hash));
		for(int j=1;number[j]<=i;j++)
		{
			hash[sg[i-number[j]]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(hash[j]==0)
			{
				sg[i]=j;
				break;
			}
		} 
	}
}
int main()
{
	for(int i=0;i<=1000;i++)
	{
		f[i]=i;
	}
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n==0) break;
		getsq(1000);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&number[i]);
		}
		for(int j=2;j<=n;j++)
		{
			number[1]=number[1]^number[j];
		}
		if(number[1]==0)
		{
			printf("Grass Win!\n");
		}else{
			
			printf("Rabbit Win!\n");
		}
	}
}
=======
#include<stdio.h>
#include<string.h>
int f[1001],number[1001],hash[1001],sg[1001];
void getsq(int n)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(hash,0,sizeof(hash));
		for(int j=1;number[j]<=i;j++)
		{
			hash[sg[i-number[j]]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(hash[j]==0)
			{
				sg[i]=j;
				break;
			}
		} 
	}
}
int main()
{
	for(int i=0;i<=1000;i++)
	{
		f[i]=i;
	}
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n==0) break;
		getsq(1000);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&number[i]);
		}
		for(int j=2;j<=n;j++)
		{
			number[1]=number[1]^number[j];
		}
		if(number[1]==0)
		{
			printf("Grass Win!\n");
		}else{
			
			printf("Rabbit Win!\n");
		}
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
