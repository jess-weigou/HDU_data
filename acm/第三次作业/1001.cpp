#include<stdio.h>
int main()
{
	int m;
	int n,max,i,k;
	double j[1005],f[1005],sum[1005],swap,sum1;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(m==-1||n==-1) break;
		for( i=0;i<n;i++)
		{
			scanf("%lf %lf",&j[i],&f[i]);
			sum[i]=j[i]/f[i];
		}
		for(i=0;i<n;i++)//½µÐòÅÅÐò 
		{
			max=i;
			for(k=i+1;k<n;k++)
			{
				if(sum[k]>sum[max]) max=k;
			}
			swap=sum[max];sum[max]=sum[i];sum[i]=swap;
			swap=j[max];j[max]=j[i];j[i]=swap;
			swap=f[max];f[max]=f[i];f[i]=swap;
		}
		i=0; 
		sum1=0.0;
		while(m>0&&i<n)
		{
			if(m>f[i])
			{
				sum1+=j[i];
				m=m-f[i];
			}else
			{
				sum1+=(m/f[i])*j[i];
				m=0;
			}
			i++;
		}
		printf("%.3lf\n",sum1);
	}
} 
