<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int n,m,dp[10002];
	int a[4]={0,150,200,350};
	scanf("%d",&n);
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&m);
		if(m<150){
			printf("%d\n",m);
			continue;
		} 
		for(int i=1;i<=3;i++)
		{
			for(int j=a[i];j<=m;j=j+1){
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}
		printf("%d\n",m-dp[m]);
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
	int n,m,dp[10002];
	int a[4]={0,150,200,350};
	scanf("%d",&n);
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&m);
		if(m<150){
			printf("%d\n",m);
			continue;
		} 
		for(int i=1;i<=3;i++)
		{
			for(int j=a[i];j<=m;j=j+1){
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}
		printf("%d\n",m-dp[m]);
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
