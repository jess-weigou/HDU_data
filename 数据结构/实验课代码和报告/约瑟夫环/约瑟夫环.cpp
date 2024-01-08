<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	struct node *prior;
	int number1;//为位序号 
	int number2;//为密码 
}node;
node* createnode(int i){//创建结点 
	node *p;
	int b;
	p=(node*)malloc(sizeof(node));//申请动态内存 
	if(p==NULL){
		printf("动态分配内存失败"); 
		exit(0);
	} 
	printf("请输入第%d个人的密码：",i);
	p->number1=i;
	scanf("%d",&p->number2);//输入密码 
	p->next=NULL;
	p->prior=NULL;
	return p;
} 
node* creat_list(int n)//连接结点 
{
	node * p;
	node * new1;
	node * head;
	if(n>=1){
		new1=createnode(1);
		head=new1;
		p=new1;
	}
	for(int i=2;i<=n;i++){//尾插法插入 
		new1=createnode(i);
		p->next=new1;
		new1->prior=p;
		p=new1;
	}
	p->next=head;//形成环 
	head->prior=p;//形成环 
	if (n>=1) return head;
}
node* delete1(node *p){//删除结点 
	node *new2;
	int static k=1;//用于标注第几个出列 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	printf("第%d个出列的位序是：%d\n",k,p->number1);//输出出列位序 
	k++;
	new2=p->next;
	p->next=NULL;
	return new2;
} 
void xunhuan(int number,node *head,int n){//用while循环输出 ,n是现存的人的个数 
	node *p=head;
	while(p!=NULL)
	{
		//number=number%n;
		if(number ==0){
			p=delete1(p->prior);
			number=p->number2;
			n--;
		}else{
			for(int i=2;i<=number;i++) p=p->next;
			number=p->number2;
			p=delete1(p);
		}
	}
} 
int main(){
	int n; //总共有多少人; 
	int number;
	node *p;
	printf("请输入人数： "); 
	scanf("%d",&n);
	p=creat_list(n);
	printf("输入第一个结束值："); 
	scanf("%d",&number); 
	xunhuan(number,p,n);
	return 0;
} 
=======
#include<stdio.h>
#include<stdlib.h>
typedef  struct node{
	struct node *next;
	struct node *prior;
	int number1;//为位序号 
	int number2;//为密码 
}node;
node* createnode(int i){//创建结点 
	node *p;
	int b;
	p=(node*)malloc(sizeof(node));//申请动态内存 
	if(p==NULL){
		printf("动态分配内存失败"); 
		exit(0);
	} 
	printf("请输入第%d个人的密码：",i);
	p->number1=i;
	scanf("%d",&p->number2);//输入密码 
	p->next=NULL;
	p->prior=NULL;
	return p;
} 
node* creat_list(int n)//连接结点 
{
	node * p;
	node * new1;
	node * head;
	if(n>=1){
		new1=createnode(1);
		head=new1;
		p=new1;
	}
	for(int i=2;i<=n;i++){//尾插法插入 
		new1=createnode(i);
		p->next=new1;
		new1->prior=p;
		p=new1;
	}
	p->next=head;//形成环 
	head->prior=p;//形成环 
	if (n>=1) return head;
}
node* delete1(node *p){//删除结点 
	node *new2;
	int static k=1;//用于标注第几个出列 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	printf("第%d个出列的位序是：%d\n",k,p->number1);//输出出列位序 
	k++;
	new2=p->next;
	p->next=NULL;
	return new2;
} 
void xunhuan(int number,node *head,int n){//用while循环输出 ,n是现存的人的个数 
	node *p=head;
	while(p!=NULL)
	{
		//number=number%n;
		if(number ==0){
			p=delete1(p->prior);
			number=p->number2;
			n--;
		}else{
			for(int i=2;i<=number;i++) p=p->next;
			number=p->number2;
			p=delete1(p);
		}
	}
} 
int main(){
	int n; //总共有多少人; 
	int number;
	node *p;
	printf("请输入人数： "); 
	scanf("%d",&n);
	p=creat_list(n);
	printf("输入第一个结束值："); 
	scanf("%d",&number); 
	xunhuan(number,p,n);
	return 0;
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
