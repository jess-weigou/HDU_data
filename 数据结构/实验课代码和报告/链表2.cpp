#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 
Polynomial ReadPoly()//读入链表 
{
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,3,&Rear);
	} 
	return P;
}
void Attach(int c,int e,,PLLYNOMIAL *pRear){
	Polynomial P；
	P= (Polynomial)malloc(sizeof(struct PolyNode));
	p->coef=c
	p->expon=e;
	p->link=NULL;
	(*pRear)->link=P;
	*pRear =P;
	}
	 
 
int main()
{
	Polynomial p1,p2,PP,PS;//p1放第一个链表，p2放第二个链表，pp乘，ps加
	P1=Readpoly(); 
	P2=Readpoly(); 
	pp=Mult(p1,p2);
	PrintPoly(pp);
	ps=add(p1,p2);
	PrintPoly(ps);
	return 0;
} 
