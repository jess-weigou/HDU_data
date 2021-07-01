#include<stdio.h>
#include<string.h>
int number[10001];
int number2[500][500];
void init()
{
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			number[2]=0;
		}
	} 
}
int main()
{
	int p=0,a,b,t=1,i=0;//p´ú±í±ß 
	init();
	memset(number,0,sizeof(number));
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0)
		{
			init();
			memset(number,0,sizeof(number));
			if(p+1==i) printf("Case %d is a tree.\n",t++);
			else printf("Case %d is not a tree.\n",t++);
//			printf("p,i: %d%d\n",p,i);
			p=0;
			i=0;
		}
		else if(a==-1&&b==-1) return 0;
		else
		{
			if(number2[a][b]==0&&number2[b][a]==0)
			{
				p++;
				number2[a][b]=1;
			}
			if(number[a]==0)
			{
				number[a]=1;
				i++;
			} 
			if(number[b]==0)
			{
				number[b]=1;
				i++;
			} 
			
		}
	}
}
