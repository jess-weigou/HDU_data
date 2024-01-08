<<<<<<< HEAD
/*姓名：应宇杰，学号：19151633*/
/*目的：合并两个有序单链表，删除key数，链表逆置*/ 
#include<stdio.h> 
#include<stdlib.h>
#define ElemType int 
struct Node{
	ElemType data;
	struct Node *next;
};
struct Node* creatlist()
{     //创造一个链表 
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));	
	headnode->next = NULL;
	return headnode;
} 
struct Node* createnode(int data)//创造新结点 
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data =data;
	newnode->next = NULL;
	return newnode;
} 
void insertnodebyhead(struct Node* headnode,int data)//头插法插入数据 
{
	struct Node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
	newnode = newnode->next;
}
//void insertnodebytail(struct Node* headnode,int data)//从尾部插入数据(未完成) 
//{
//	struct Node* newnode = createnode(data);
//	newnode->next=NULL
//	headnode->next = newnode;  
//}
void printlist(struct Node* headnode)//打印链表 
{
	struct Node* pmove=headnode->next;
	while(pmove)
	{
		printf("%d",pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
} 
void delnode(struct Node* headnode,int data)//删除值为data的结点 
{
	struct Node* pmove1=headnode->next;
	struct Node* pmove2=headnode;
	while(pmove1!=NULL)
	{
		if(pmove1->data==data)
		{
			pmove2->next = pmove1->next;
			free(pmove1);
			pmove1=pmove2->next;
		}else{
			pmove2 = pmove1;
			pmove1 = pmove2->next;
		}
	}
}
void nizhinode(struct Node* headnode) //链表逆置 
{
	struct Node* q = headnode->next;
	struct Node* p ;
	headnode->next = NULL;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		p->next = headnode->next;
		headnode->next = p; 
	}
}
void addnode(struct Node* list1,struct Node* list2,struct Node* list3) //合并链表，把合并的链表放到list3上面 
{
	struct Node* p = list1->next;
	struct Node* q = list2->next;
	
	struct Node* c = list3;
	c->next=NULL; 
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<=q->data)
		{
			c->next=p;
			c=p;
			p=p->next;
		}else{
			c->next=q;
			c=q;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		c->next=p;
		c=p;
		p=p->next;
	}
	while(q!=NULL)
	{
		c->next=q;
		c=q;
		q=q->next;
	}
	
}
int main()
{
	struct Node* list1=creatlist();
	struct Node* list2=creatlist();
	struct Node* list3=creatlist();
	insertnodebyhead(list1,3);//链表输入3458四个数并且打印 
	insertnodebyhead(list1,4);
	insertnodebyhead(list1,5);
	insertnodebyhead(list1,8);
	insertnodebyhead(list1,2);
	printf("打印链表1: ");printlist(list1);
	nizhinode(list1);//链表逆置并且打印
	printf("打印逆置链表1: ");printlist(list1);
	delnode(list1,2); //链表删除2并且打印 
	printf("删除链表1中的数字2并且打印: ");printlist(list1);
	insertnodebyhead(list2,9);//链表输入 289三个数 
	insertnodebyhead(list2,8);
	insertnodebyhead(list2,2);
	printf("打印链表2: ");printlist(list2);
	addnode(list1,list2,list3);//合并两个链表 
	printf("打印合并的俩个链表: ");printlist(list3);
	return 0;
}
=======
/*姓名：应宇杰，学号：19151633*/
/*目的：合并两个有序单链表，删除key数，链表逆置*/ 
#include<stdio.h> 
#include<stdlib.h>
#define ElemType int 
struct Node{
	ElemType data;
	struct Node *next;
};
struct Node* creatlist()
{     //创造一个链表 
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));	
	headnode->next = NULL;
	return headnode;
} 
struct Node* createnode(int data)//创造新结点 
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data =data;
	newnode->next = NULL;
	return newnode;
} 
void insertnodebyhead(struct Node* headnode,int data)//头插法插入数据 
{
	struct Node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
	newnode = newnode->next;
}
//void insertnodebytail(struct Node* headnode,int data)//从尾部插入数据(未完成) 
//{
//	struct Node* newnode = createnode(data);
//	newnode->next=NULL
//	headnode->next = newnode;  
//}
void printlist(struct Node* headnode)//打印链表 
{
	struct Node* pmove=headnode->next;
	while(pmove)
	{
		printf("%d",pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
} 
void delnode(struct Node* headnode,int data)//删除值为data的结点 
{
	struct Node* pmove1=headnode->next;
	struct Node* pmove2=headnode;
	while(pmove1!=NULL)
	{
		if(pmove1->data==data)
		{
			pmove2->next = pmove1->next;
			free(pmove1);
			pmove1=pmove2->next;
		}else{
			pmove2 = pmove1;
			pmove1 = pmove2->next;
		}
	}
}
void nizhinode(struct Node* headnode) //链表逆置 
{
	struct Node* q = headnode->next;
	struct Node* p ;
	headnode->next = NULL;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		p->next = headnode->next;
		headnode->next = p; 
	}
}
void addnode(struct Node* list1,struct Node* list2,struct Node* list3) //合并链表，把合并的链表放到list3上面 
{
	struct Node* p = list1->next;
	struct Node* q = list2->next;
	
	struct Node* c = list3;
	c->next=NULL; 
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<=q->data)
		{
			c->next=p;
			c=p;
			p=p->next;
		}else{
			c->next=q;
			c=q;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		c->next=p;
		c=p;
		p=p->next;
	}
	while(q!=NULL)
	{
		c->next=q;
		c=q;
		q=q->next;
	}
	
}
int main()
{
	struct Node* list1=creatlist();
	struct Node* list2=creatlist();
	struct Node* list3=creatlist();
	insertnodebyhead(list1,3);//链表输入3458四个数并且打印 
	insertnodebyhead(list1,4);
	insertnodebyhead(list1,5);
	insertnodebyhead(list1,8);
	insertnodebyhead(list1,2);
	printf("打印链表1: ");printlist(list1);
	nizhinode(list1);//链表逆置并且打印
	printf("打印逆置链表1: ");printlist(list1);
	delnode(list1,2); //链表删除2并且打印 
	printf("删除链表1中的数字2并且打印: ");printlist(list1);
	insertnodebyhead(list2,9);//链表输入 289三个数 
	insertnodebyhead(list2,8);
	insertnodebyhead(list2,2);
	printf("打印链表2: ");printlist(list2);
	addnode(list1,list2,list3);//合并两个链表 
	printf("打印合并的俩个链表: ");printlist(list3);
	return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006
