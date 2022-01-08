#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void merge(int num[],int l1,int r1,int l2,int r2){
	int size1 = r1 - l1;
	int size2 = r2 - l2;
	int *arr1 = (int *)malloc(sizeof(int)*size1);
	int *arr2 = (int *)malloc(sizeof(int)*size2);
	for(int i=0;i<size1;i++){
		arr1[i] = num[l1+i];
	}
	for(int i=0;i<size2;i++){
		arr2[i] = num[l2+i];
	}
	int *arr3;
	if( l1 < l2){
		arr3 = num+l1;
	}else{
		arr3 = num+l2;
	}
	int p=0,q=0,a=0;
	while(p<size1 && q<size2){
		if(arr1[p] < arr2[q]){
			arr3[a] = arr1[p];
			a++;
			p++;
		}else{
			arr3[a] = arr2[q];
			a++;
			q++;
		}
	}
	if(p<size1){
		while(p<size1){
			arr3[a] = arr1[p];
			p++;
			a++;
		}
	}else if(q<size2){
		while(q<size2){
			arr3[a] = arr2[q];
			q++;
			a++;
		}
	}
}
//选择排序 
int sort(int* arr, int size)
{
	if (size == 0)
	{
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}
void devide(int num[],int l,int r){
	int size = r-l;
	int sq = sqrt(size);
	if(size >3){
		//分出根号n个区块
		 for(int i=0;i<sq;i++){
		 	devide(num,l+i*sq,l+(i+1)*sq);
		 } 
		 //为了把最后的数字也排序进去 
		 devide(num,l+sq*(sq-1),r);
	}else{
		sort(num+l,size);
	}
	//合并根号n个区块 
	int firstl =  l;
	int firstr = l+sq;
	for(int i=1;i<sq;i++){
		int lastl = l +sq*i;
		int lastr = lastl+sq;
		merge(num,firstl,firstr,lastl,lastr);
		firstr += sq;
	}
	merge(num,firstl,firstr,firstr,r); 
}

int main(){
	int n;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	devide(num,0,n);
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
} 

