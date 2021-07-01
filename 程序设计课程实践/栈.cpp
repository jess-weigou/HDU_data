#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
stack<int>  s;
int b[1000];

int main(){
	int a;
	int k=0;
	while(scanf("%d",&a)!=EOF&&a!=0){
		if (a>0){
			s.push(a);
		}else{
			b[k++]=a;
		}
	}
	while(!s.empty()){
		printf("%5d",s.top());
		s.pop();
	}
	printf("\n");
	for(int i=0;i<k;i++){
		printf("%5d",b[i]);
	}
	printf("\n");
} 
