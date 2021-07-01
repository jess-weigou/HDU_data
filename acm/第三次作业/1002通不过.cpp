#include<stdio.h>
int swap(int a,int b)
{
	int j;
	j=a;
	a=b;
	b=j;
}
int main(){
	int a,b,c,d;
	int p[205];
	int max;
	
	scanf("%d",&a);
	while(a--)
	{
		bool flag=true; 
		for(int i=0;i<205;i++) p[i]=0; 
		scanf("%d",&b);
		for(int j=0;j<b;j++)
		{
			scanf("%d %d",&c,&d);
			if(c>d) swap(c,d);
			c=(c+1)/2;
			d=(d+1)/2;
			if(flag==true&&c==d) p[c]++;
			for(int i=c;i<d;i++) p[i]++; 
			flag=false;
		}
		max=0;
		for(int j=0;j<205;j++)
		{
			if(p[j]>max) max=p[j];
		}
		if(a==1) printf("%d",max*10);
		else printf("%d\n",max*10);
	}
} 
