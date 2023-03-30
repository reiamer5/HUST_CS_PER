#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
//#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 200
typedef int ElemType;
typedef int Status;
typedef int Boolean;
int count=0;
/*
题目1201：二叉排序树
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3613解决：1540
题目描述：
    输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
输入：
    输入第一行包括一个整数n(1<=n<=100)。
    接下来的一行包括n个整数。
输出：
    可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
    每种遍历结果输出一行。每行最后一个数据之后有一个空格。
样例输入：
6
1 6 5 9 8 8
样例输出：
1 6 5 9 8 
1 5 6 8 9 
5 8 9 6 1 
提示：
输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。

*/
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树T上寻找值为key的节点 若查找成功 parent指向该节点 并返回TRUE 
//否则parent指向查找路径上的最后一个节点 返回FALSE
Status searchBST(BSTree T,ElemType key,BSTNode *f,BSTNode **parent)
{		//printf("**%d ",key);
	if(T==NULL)
	{
		*parent=f;
		return FALSE;//查找不成功
	}
	else if(T->data==key)
	{
	
		return TRUE;//查找成功
	}
	else if(T->data>key)
	{
		return searchBST(T->lchild,key,T,parent);//在左子树上继续查找
	}
	else
	{
		return searchBST(T->rchild,key,T,parent);//在右子树上继续查找
	}
}

//按data中的数据建立二叉排序树
Status createBST(BSTree *T,ElemType data[N],int n)
{

	int i=0;
	BSTNode * parent=NULL;
	BSTNode *s=NULL;
	while(i<n)//while 1#
	{
		if(searchBST(*T,data[i],NULL,&parent)==FALSE)//查找失败
		{
			count++;
			s=(BSTNode *)malloc(sizeof(BSTNode));
			s->data=data[i];
			s->lchild=NULL;
			s->rchild=NULL;
		
			if(parent==NULL)//建立根节点
			{
				*T=s;
			}
			else if(parent->data>data[i])
			{
				parent->lchild=s;
			}
			else
			{
				parent->rchild=s;
			}
		}
		i++;			
	}//end:while 1#

	return OK;
}
//先序遍历二叉树
Status preOrderTraverse(BSTree T,ElemType printStr[N],int *i)
{
	if(T!=NULL)
	{
		//printf("%c",T->data);
		printStr[*i]=T->data;
		(*i)++;
	}
	if(T->lchild!=NULL)
	{
		preOrderTraverse(T->lchild,printStr,i);
	}
	if(T->rchild!=NULL)
	{
		preOrderTraverse(T->rchild,printStr,i);
	}
	return OK;
}
//中序遍历二叉树
Status inOrderTraverse(BSTree T,ElemType printStr[N],int *i)
{
	if(T->lchild!=NULL)
	{
		inOrderTraverse(T->lchild,printStr,i);
	}
	if(T!=NULL)
	{
		//printf("%c",T->data);
		printStr[*i]=T->data;
		(*i)++;
	}
	if(T->rchild!=NULL)
	{
		inOrderTraverse(T->rchild,printStr,i);
	}
	return OK;
}

//后序遍历二叉树
Status postOrderTraverse(BSTree T,ElemType printStr[N],int *i)
{
	if(T->lchild!=NULL)
	{
		postOrderTraverse(T->lchild,printStr,i);
	}	
	if(T->rchild!=NULL)
	{
		postOrderTraverse(T->rchild,printStr,i);
	}
	if(T!=NULL)
	{
		//printf("%c",T->data);
		printStr[*i]=T->data;
		(*i)++;
	}
	return OK;
}
void DestroyBiTree(BSTree *T)
 { /* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
   if(*T) /* 非空树 */
   {
     if((*T)->lchild) /* 有左孩子 */
       DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
     if((*T)->rchild) /* 有右孩子 */
       DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
     free(*T); /* 释放根结点 */
     *T=NULL; /* 空指针赋0 */
   }
 }
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	ElemType data[N];
	ElemType printStr[N];
	BSTree T=NULL;
	int n=0;
	int i=0;
	int k=0;
	int i1,i2,i3;
	while(scanf("%d",&n)!=EOF)
	{	
		count=0;
		i1=i2=i3=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		createBST(&T,data,n);	
		preOrderTraverse(T,printStr,&i1);
		for(k=0;k<count;k++)
		{
			printf("%d ",printStr[k]);
		}
		printf("\n");

		inOrderTraverse(T,printStr,&i2);
		for(k=0;k<count;k++)
		{
			printf("%d ",printStr[k]);
		}
		printf("\n");

		postOrderTraverse(T,printStr,&i3);
		for(k=0;k<count;k++)
		{
			printf("%d ",printStr[k]);
		}
		printf("\n");

		DestroyBiTree(&T);
		
	}
	return OK;
}

int main()
{
	if(ERROR==service())//解决方案出错
	{
		printf("ERROR!\n");
		return ERROR;
	}

	return OK;

}