<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<math.h>
#define mod 99991
int main()
{
	const int lizi[7]={13,131,1313,13131,131313,1313131,13131313};
	int n,c[mod+1],k;
	char num[200],num1[200],temp[200];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int tmp=0;
		int ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",num);
			int len=strlen(num);
			for(int j=0;j<len;j++)
			{
				tmp=(tmp*307+num[j]) % mod;
			}
			if(++c[tmp]>ans){
				ans=c[tmp];
				strcpy(num1,num);
			} 
			tmp=0;
		}
		printf("%s\n",num1);	
	}
	return 0;
} 
=======
#include<stdio.h>
#include<string.h>
#include<math.h>
#define mod 99991
int main()
{
	const int lizi[7]={13,131,1313,13131,131313,1313131,13131313};
	int n,c[mod+1],k;
	char num[200],num1[200],temp[200];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int tmp=0;
		int ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",num);
			int len=strlen(num);
			for(int j=0;j<len;j++)
			{
				tmp=(tmp*307+num[j]) % mod;
			}
			if(++c[tmp]>ans){
				ans=c[tmp];
				strcpy(num1,num);
			} 
			tmp=0;
		}
		printf("%s\n",num1);	
	}
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
