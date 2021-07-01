#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	int number1;//为位序号 
}node;
int arr2[10];
node* createnode(int i){//创建结点 
	node *p;
	p=(node*)malloc(sizeof(node));//申请动态内存 
	if(p==NULL){
		printf("动态分配内存失败"); 
		exit(0);
	} 
	p->number1=i;
	p->next=NULL;
	return p;
} 
node* creat_list(int n,int arr[])//连接结点 
{
	node * p;
	node * new1;
	node * head;
	new1=createnode(arr[0]);
	head=new1;
	p=new1;
	for(int i=1;i<n;i++){//尾插法插入 
		new1=createnode(arr[i]);
		p->next=new1;
		p=new1;
	}
	p->next=head;//形成环 
	return head;
}
//打印出局结点 
node* print(node *p,int flag){
	node *new2;
	int static k=0;//用于标注第几个出列 
	new2=p->next;
	if(flag==1){
		printf("%4d",p->next->number1);//输出出列位序
	}else{
		arr2[k++]=p->next->number1;
	}
	
	 
	p->next=p->next->next; 
	free(new2);
	return p->next;
} 
void loop(int number,node *head,int n,int flag){
	node *p=head;
	int count=0;
	while(count<n)
	{
		for(int i=0;i<number-2;i++){
			p=p->next;
		}
		p=print(p,flag);
		count++;
	}
} 
int main(){
	int n; 
	int number1,number2;
	node *head;
	scanf("%d",&n);
	int  arr[n];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}
	head=creat_list(n,arr);
	scanf("%d%d",&number1,&number2); 
	loop(number1,head,n,0);
	head=creat_list(n,arr2);
	loop(number2,head,n,1);
	return 0;
}



