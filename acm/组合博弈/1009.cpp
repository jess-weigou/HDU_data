<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int s[102],sg[10002],hash[102],number;
int cmp( const void *a , const void *b )
{
 	return *(int *)a - *(int *)b;
}
void find(int n9)
{
	int t;
	for(int i=1;i<=n9;i++)
	{
		memset(hash,0,sizeof(hash));
		for(int j=1;j<=n;j++)
		{
			t=i-s[j];
			if(t<0) break;
			hash[sg[t]]=1;	
		}
		for(int j=0;j<10001;j++)
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
	int n1,n2,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break; 
		memset(sg,-1,sizeof(sg));
		sg[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
		}
		s[0]=-1; 
		qsort(s,n+1,sizeof(s[0]),cmp); //很重要 
		scanf("%d",&n1);
		find(10000);
		while(n1--)
		{
			scanf("%d",&n2);
			int ans=0;
			while(n2--)
			{
				scanf("%d",&number);
				ans^=sg[number];
			}
			if(ans==0) printf("L");
			else printf("W");
		}
		printf("\n");
	}
} 
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int s[102],sg[10002],hash[102],number;
int cmp( const void *a , const void *b )
{
 	return *(int *)a - *(int *)b;
}
void find(int n9)
{
	int t;
	for(int i=1;i<=n9;i++)
	{
		memset(hash,0,sizeof(hash));
		for(int j=1;j<=n;j++)
		{
			t=i-s[j];
			if(t<0) break;
			hash[sg[t]]=1;	
		}
		for(int j=0;j<10001;j++)
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
	int n1,n2,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break; 
		memset(sg,-1,sizeof(sg));
		sg[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
		}
		s[0]=-1; 
		qsort(s,n+1,sizeof(s[0]),cmp); //很重要 
		scanf("%d",&n1);
		find(10000);
		while(n1--)
		{
			scanf("%d",&n2);
			int ans=0;
			while(n2--)
			{
				scanf("%d",&number);
				ans^=sg[number];
			}
			if(ans==0) printf("L");
			else printf("W");
		}
		printf("\n");
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
