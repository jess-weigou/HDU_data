<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int father[10001];
double sum;
typedef struct{
	int from ;
	int to;
	double value;
}Node,*node; 
Node mp[10000];
int find(int x)
{
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void merge(int i)
{
	int a=find(mp[i].from);
	int b=find(mp[i].to);
	if(a!=b&&mp[i].value>=10&&mp[i].value<=1000){
		father[a]=b;
		sum+=mp[i].value;
	} 
	
}
int cmp(const Node &x,const Node &y){
       
       return xx.value-yy.value;
  }
int main()
{
	int t,n;
	double number1[101],number2[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<10000;i++)//初始化 
		{
			father[i]=i;
		} 
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&number1[i],&number2[i]);
		}
		int k=0;
		for(int i=0;i<n;i++)//输入两岛屿距离 
		{
			for(int j=i+1;j<n;j++)
			{
				sum=sqrt(pow(number1[i]-number1[j],2)+pow(number2[i]-number2[j],2));
				if(sum>=10&&sum<=1000)
				{
					mp[k].value=sum;
					mp[k].from=j;
					mp[k].to=i;
					k++;
				}
			} 
		} 
		sum=0;
		int m=0,i;
		qsort(mp,k-1,sizeof(mp[0]),cmp);//从第一个开始排序
		for(int i=0;i<k;i++)
		{
			merge(i);
		}
//		if(sum<=0) printf("oh!\n");
//		else printf("%.1lf\n",sum*100);
		for( i=0,m=0;i<n;i++)
        {
            if(m>1)
            {
                printf("oh!\n");
                break;
            }
            else if(father[i]==i)
                m++;
        }
        if(m==1)
            printf("%.1lf\n",100*sum);
	} 
	return 0;
}

=======
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int father[10001];
double sum;
typedef struct{
	int from ;
	int to;
	double value;
}Node,*node; 
Node mp[10000];
int find(int x)
{
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void merge(int i)
{
	int a=find(mp[i].from);
	int b=find(mp[i].to);
	if(a!=b&&mp[i].value>=10&&mp[i].value<=1000){
		father[a]=b;
		sum+=mp[i].value;
	} 
	
}
int cmp(const Node &x,const Node &y){
       
       return xx.value-yy.value;
  }
int main()
{
	int t,n;
	double number1[101],number2[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<10000;i++)//初始化 
		{
			father[i]=i;
		} 
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&number1[i],&number2[i]);
		}
		int k=0;
		for(int i=0;i<n;i++)//输入两岛屿距离 
		{
			for(int j=i+1;j<n;j++)
			{
				sum=sqrt(pow(number1[i]-number1[j],2)+pow(number2[i]-number2[j],2));
				if(sum>=10&&sum<=1000)
				{
					mp[k].value=sum;
					mp[k].from=j;
					mp[k].to=i;
					k++;
				}
			} 
		} 
		sum=0;
		int m=0,i;
		qsort(mp,k-1,sizeof(mp[0]),cmp);//从第一个开始排序
		for(int i=0;i<k;i++)
		{
			merge(i);
		}
//		if(sum<=0) printf("oh!\n");
//		else printf("%.1lf\n",sum*100);
		for( i=0,m=0;i<n;i++)
        {
            if(m>1)
            {
                printf("oh!\n");
                break;
            }
            else if(father[i]==i)
                m++;
        }
        if(m==1)
            printf("%.1lf\n",100*sum);
	} 
	return 0;
}

>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
