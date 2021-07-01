#include <stdio.h>
#include<malloc.h>
#include <malloc.h>
typedef struct BiTNode
{
	char data;  /*结点的数据域*/
	struct BiTNode *lchild , *rchild; /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

/*创建一棵二叉树*/
void CreatBiTree(BiTree *T)
{

	char c;
	scanf("%c",&c);
	if(c == '#') 
		*T = NULL;
	else
	{
		*T = (BiTNode * )malloc(sizeof(BiTNode)); /*创建根结点*/
		(*T)->data = c; /*向根结点中输入数据*/
		CreatBiTree(&((*T)->lchild)); /*递归地创建左子树*/
		CreatBiTree(&((*T)->rchild)); /*递归地创建右子树*/
	}
}

//计算二叉树的深度
int getBitreeDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;//左子树，右子树，最大深度
	if (T != NULL) //如果为空树
	{
		leftHeight = getBitreeDepth(T->lchild);//左子树深度
		rightHeight = getBitreeDepth(T->rchild);//右子树深度
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//最大深度
		return maxHeight+1;//二叉树深度=最大深度+1
	}
	else
	{
		return 0;
	}
}

void main()
{
	BiTree T = NULL; /*最开始T指向空*/
		printf("请您输入一个二叉树（以#为空子树）：\n");
	CreatBiTree(&T); /*创建二叉树*/
		printf("\n二叉树的深度为%d\n",getBitreeDepth(T));
}



