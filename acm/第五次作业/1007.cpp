<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char heng[1002];
char shu[1002];
int shuzu[10002][10002];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{

	int i=0,j=0;
	int a,b;
	while(scanf("%s %s",heng,shu)!=EOF)
	{
		a=strlen(heng);
		b=strlen(shu);
//		printf("%d %d",a,b);
		memset(shuzu,0,sizeof(shuzu[0]));
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(heng[i-1]==shu[j-1])
				{
					shuzu[i][j]=shuzu[i-1][j-1]+1;
				}else{
					shuzu[i][j]=max(shuzu[i-1][j],shuzu[i][j-1]);
				}
			}
		}
		printf("%d\n",shuzu[a][b]);
		memset(heng,0,sizeof(heng));
		memset(shu,0,sizeof(shu));
	} 
	return 0;
} 
=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char heng[1002];
char shu[1002];
int shuzu[10002][10002];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{

	int i=0,j=0;
	int a,b;
	while(scanf("%s %s",heng,shu)!=EOF)
	{
		a=strlen(heng);
		b=strlen(shu);
//		printf("%d %d",a,b);
		memset(shuzu,0,sizeof(shuzu[0]));
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(heng[i-1]==shu[j-1])
				{
					shuzu[i][j]=shuzu[i-1][j-1]+1;
				}else{
					shuzu[i][j]=max(shuzu[i-1][j],shuzu[i][j-1]);
				}
			}
		}
		printf("%d\n",shuzu[a][b]);
		memset(heng,0,sizeof(heng));
		memset(shu,0,sizeof(shu));
	} 
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
