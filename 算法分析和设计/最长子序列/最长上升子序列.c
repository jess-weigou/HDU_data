#include<stdio.h>
int max(int a,int b){
    return a>b? a:b;
}
int main(){
    int num[]={1,7,3,5,9,4,8};
    int n=7;
    int arr[n];
    int maxnum = 1;
    for(int i=0;i<n;i++){
        arr[i] = 1;
    }
    for(int i=1;i<n; i++){
        for(int j = 0;j < i; j++){
            if(num[i] > num[j]){
                arr[i] = max(arr[i] , arr[j]+1);
            }
            maxnum = max(arr[i] , maxnum);
        }
    }
    printf("%d\n",maxnum);
}