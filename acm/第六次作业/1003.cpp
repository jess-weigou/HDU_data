<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int t,m,n;
	int p[101],h[101],c[101];
	int dp[105];
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&p[i],&h[i],&c[i]);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=0;j--)
			{
				for(int k=1;k<=c[i];k++) 
				{
					if(j>=k*p[i]) dp[j]=max(dp[j],dp[j-k*p[i]]+k*h[i]);
				}
			}
		}
		printf("%d\n",dp[n]);
	}
} 
=======
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int t,m,n;
	int p[101],h[101],c[101];
	int dp[105];
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&p[i],&h[i],&c[i]);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=0;j--)
			{
				for(int k=1;k<=c[i];k++) 
				{
					if(j>=k*p[i]) dp[j]=max(dp[j],dp[j-k*p[i]]+k*h[i]);
				}
			}
		}
		printf("%d\n",dp[n]);
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
