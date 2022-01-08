#include<stdio.h>
void devide(int *max,int *min,int num[],int l,int r){
    int max1,min1;
    if(l>r) return ;
    else if(l == r){
        *max = num[l];
        *min = num[l];
    }else if(r-1 ==l){
        if(num[l] > num[r]){
            *max = num[l];
            *min = num[r];
        }else{
            *max = num[r];
            *min = num[l];
        }
    }else{
        int middle =(l+r)/2;
        devide(max,min,num,l,middle);
        devide(&max1,&min1,num,middle+1,r);
        if(*max <max1){
            *max = max1;
        }
        if(*min >min1){
            *min = min1;
        }
    }
}
int main(){
    int test[10] ={1,52,5,-1,2512532,13,2,86,159,4};
    int max =-111111;
    int min =99999999;
    devide(&max,&min,test,0,9);
    printf("max: %d min: %d",max,min);
    return 0;
}

