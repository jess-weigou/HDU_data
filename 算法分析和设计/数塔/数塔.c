#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if(a >b ){
        return a;
    }else{
        return b;

    }
}
int main(){
    int n;
    int num[100][100];
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&num[i][j]);
            
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0 ; j<=i; j++){
            num[i][j] +=  max(num[i+1][j] , num[i+1][j+1]);
        }
    }
}