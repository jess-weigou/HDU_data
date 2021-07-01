#include<stdio.h>
#include<math.h>
#include<string.h>
int min(int a,int b){
    return a>b? b:a;
}
int main(){
    int num[100][100];
    int k;
    char s1[100],s2[100];
    scanf("%s%s",s1 , s2);
    scanf("%d",&k);
    memset(num,0,sizeof(num));
    int maxlen = strlen(s1) > strlen(s2) ?strlen(s1) :strlen(s2); 
    for(int i=1;i<=maxlen;i++){
        for(int j=1;j<=maxlen;j++){
            if(i==1&&j==1){
                num[i][j] = min(k,fabs(s1[i-1]-s2[j-1]));
            }else if(j==1 &&i >1){
                num[i][j] = min(num[i-1][j]+k,fabs(s1[i-1]-s2[j-1]));
            }else if(i==1 && j>1){
                num[i][j] = min(num[i][j-1]+k,fabs(s1[i-1]-s2[j-1]));
            }else{
                num[i][j] = min(min(num[i-1][j]+k,num[i][j-1]+k),num[i-1][j-1]+ fabs(s1[i-1]-s2[j-1]));
            }
            
        }
    }
    // for(int i=1;i<=maxlen;i++){
    //     for(int j=1;j<=maxlen;j++){
    //         if(j==maxlen){
    //             printf("%d\n",num[i][j]);
    //         }else
    //             printf("%d ",num[i][j]);
    //         }
            
    //     }
    printf("%d\n",num[maxlen][maxlen]);
    return 0;
}