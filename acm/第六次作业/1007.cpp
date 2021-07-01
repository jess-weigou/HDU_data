#include<stdio.h>
#include<string.h>
double min(double a,double b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	double v[10002];
	int   w[10002];
	double dp[10002];
	double c[10002];
	int n,l,flag;
	while(scanf("%d %d",&l,&n)!=EOF)
	{
		if(l==0&&n==0) break;
		for(int i=0;i<=l;i++){
			dp[i]=1;
		}
//		for(int i=1;i<=l;i++){
//			printf("%f ",dp[i]);
//		}
		for(int i=1;i<=n;i++) scanf("%d %lf",&w[i],&v[i]);
		for(int i=1;i<=n;i++) c[i]=1.0-v[i];
		for(int i=1;i<=n;i++) 
		{
			for(int j=l;j>=w[i];j--)
			{
				dp[j]=min(dp[j],dp[j-w[i]]*c[i]);
			}
		}
//		for(int i=1;i<=l;i++){
//			printf("%f ",dp[i]);
//		}
		printf("%.1lf%%\n",(1.0-dp[l])*100);
	}
	return 0;
} 
