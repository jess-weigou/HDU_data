#include<stdio.h>
#include<string.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int n,v;
	int number;
	int a[1001];//ÓÃÓÚ´¢´æ¹Ç÷ÀÖµ 
	int b[1001];
    int d[1003][1003] ;
	scanf("%d",&n);
	while(n--){
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d %d",&number,&v);
		for(int i=1;i<=number;i++) scanf("%d",&a[i]);
		for(int i=1;i<=number;i++) scanf("%d",&b[i]);
		for(int i=1;i<=number;i++){
			for(int j=0;j<=v;j++){
				if(b[i]>j){
					d[i][j]=d[i-1][j];
				}else{
					d[i][j]=max(d[i-1][j],d[i-1][j-b[i]]+a[i]);
				}
			}
		} 
		printf("%d\n",d[number][v]);
	}
	return 0;
} 
