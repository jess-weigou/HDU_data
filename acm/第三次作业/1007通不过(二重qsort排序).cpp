#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct position{
	float x;
	float y;
};
int cmp(const void *e,const void *b)
{
	struct position *c=(position *)e;
	struct position *d=(position *)b;
	if(c->x!=d->x) return c->x-d->x;
	else return c->x-d->x;
}
double dist(struct position a,struct position b){
    return (sqrt((a.x-b.x) * (a.x-b.x) + (a.y - b.y) * (a.y - b.y)));
}
int main()
{
	int n;
	double min,swap; 
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		struct position a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%f",&a[i].x);
			scanf("%f",&a[i].y);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		min=dist(a[0],a[1]);
		if(n<=5)
		{
			for(int k=0;k<n;k++)
			{
				for(int j=k+1;j<n;j++)
				{
					swap=dist(a[k],a[j]);
					if(swap<min) min=swap;
				} 
			}
		}else{
			for(int i=0;i<n-5;i++)
			{
				for(int j=i+1;j<i+6;j++)
				{
					swap=dist(a[i],a[j]);
					if(swap<min) min=swap;
				}
			} 
			for(int k=n-5;k<n;k++)
			{
				for(int j=k+1;j<n;j++)
				{
					swap=dist(a[k],a[j]);
					if(swap<min) min=swap;
				} 
			}
		}
		printf("%.2lf\n",min/2);
	}
	return 0;
} 
