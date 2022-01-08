#include<stdio.h>
#include<string.h>
int divide_max(int arr[],int left,int right){
	int max1=-100000;
    int max2=-100000;
	if (left==right){
		return arr[left];
	}else if (right-left==1){
		return arr[right]>arr[left]?arr[right]:arr[left];
	}else{
		int mid=(left+right)/2;
		max1=divide_max(arr,left,mid);
		max2=divide_max(arr,mid+1,right);
		return max1>max2?max1:max2;
	}
}
int divide_min(int arr[],int left,int right){
	int min1=99999;
    int min2=9999;
	if (left==right){
		return arr[left];
	}else if (right-left==1){
		return arr[right]<arr[left]?arr[right]:arr[left];
	}else{
		int mid=(left+right)/2;
		min1=divide_min(arr,left,mid);
		min2=divide_min(arr,mid+1,right);
		return min1<min2?min1:min2;
	}
}
int main(){
	int arr[10002];
	int n=0;
	memset(arr,0,sizeof(arr));
	while(scanf("%d",&arr[n++])!=EOF&&arr[n-1]!=0);
	int max=divide_max(arr,0,n-2);
	int min=divide_min(arr,0,n-2);
	printf("%d,%d",min,max);
	return 0;
}

