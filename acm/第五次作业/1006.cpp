#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct numbers{
	int n1;//体重 
	int n2;//速度 
	int n3;//前面有几个 
	int n4;//序号 
	int pre; 
}number[1002];
int cmp(const void *a,const void *b)
{
	struct numbers *c=(numbers *)a;
	struct numbers *d=(numbers *)b;
	if(c->n1!=d->n1) return c->n1-d->n1;
	else return c->n2-d->n2;
	
}
void output(int k){
    if(number[k].n3==1)
        printf("%d\n",number[k].n4);
    else{
        output(number[k].pre);
        printf("%d\n",number[k].n4);
    }
}
int main()
{
	int shunxu[1000];
	int n=1,a,b;
	int max=1,max2=0;
	memset(&number,0,sizeof(number[0]));
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		number[n].n1 =a;
		number[n].n2 =b;
		number[n].n3=1;
		number[n].n4=n;
		n++;

	}	
	qsort(number,n,sizeof(number[0]),cmp);
//	for(int i=1;i<=n;i++)
//	{
//		printf("shuju: %d %d\n",number[i].n1,number[i].n2); 
//	}		
	int k=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
				
			if(number[i].n2<number[j].n2&&max2<number[j].n3)
			{					
				max2=number[j].n3;
				number[i].pre=j;
			}
		}
		number[i].n3+=max2;
		if(number[max].n3<=number[i].n3) max=i;
		max2=0;
	}
		printf("%d\n",number[max].n3);
		output(max);
		max=0;
	
} 
