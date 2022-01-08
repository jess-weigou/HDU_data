#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef  struct bitnode{
	struct bitnode *lchild,*rchild;
	char data;
}bitnode ,*bitree;
create(bitree *t)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#') *t=NULL;
	else{
		*t =(bitnode*)malloc(sizeof(bitnode));
		(*t)->data=ch;
		create(&(*t)->lchild);
		create(&(*t)->rchild);	
	} 
}
visit(char c,int level){
	printf("%c 位于第%d层\n",c,level);
} 
void inorder(bitree t)//非递归遍历 
{
	int i=0;
	bitree s[100];//用于进栈出栈 
	bitree r;
	r=t;
	do{
		while(r!=NULL)
		{
			printf("%c\n",r->data);
			if(r->rchild!=NULL){
				s[i]=r->rchild;
				i=i+1;
//				printf("%d\n",i); 
			} 
			r=r->lchild;
		}
		if(i>0){
			i=i-1;
			r=s[i];
		} 
	}while(i>0||r!=NULL);
}
order(bitree t,int level){//递归遍历 
	if(t){
		visit(t->data,level);
		order(t->lchild,level+1);
		order(t->rchild,level+1);
	}
}
int main()
{
	bitree t;
	int level=1; 
	create(&t);
	printf("接下来是前序循环遍历：\n");
	order(t,level);
	printf("接下来是前序非循环遍历：\n");
	inorder(t) ;
	return 0;
}

