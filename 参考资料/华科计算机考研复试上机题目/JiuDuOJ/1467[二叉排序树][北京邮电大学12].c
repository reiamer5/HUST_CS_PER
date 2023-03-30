#include<stdio.h>
//#include<string.h>
#include<malloc.h>
//#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

typedef int ElemType;

//#define M 1000
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1467：二叉排序树
时间限制：1 秒内存限制：128 兆特殊判题：否提交：2499解决：1024
题目描述：
        二叉排序树，也称为二叉查找树。可以是一颗空树，也可以是一颗具有如下特性的非空二叉树：

        1. 若左子树非空，则左子树上所有节点关键字值均不大于根节点的关键字值；
        2. 若右子树非空，则右子树上所有节点关键字值均不小于根节点的关键字值；
        3. 左、右子树本身也是一颗二叉排序树。

　　现在给你N个关键字值各不相同的节点，要求你按顺序插入一个初始为空树的二叉排序树中，每次插入后成功后，求相应的父亲节点的关键字值，如果没有父亲节点，则输出-1。
输入：
输入包含多组测试数据，每组测试数据两行。
第一行，一个数字N（N<=100），表示待插入的节点数。
第二行，N个互不相同的正整数，表示要顺序插入节点的关键字值，这些值不超过10^8。
输出：
输出共N行，每次插入节点后，该节点对应的父亲节点的关键字值。
样例输入：
5
2 5 1 3 4
样例输出：
-1
2
2
5
3
来源：
2012年北京邮电大学计算机研究生机试真题
*/

typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
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
			s=(BSTNode *)malloc(sizeof(BSTNode));
			s->data=data[i];
			s->lchild=NULL;
			s->rchild=NULL;
		
			if(parent==NULL)//建立根节点
			{
				*T=s;
				printf("-1\n");
			}
			else if(parent->data>data[i])
			{
				parent->lchild=s;
				printf("%d\n",parent->data);
			}
			else
			{
				parent->rchild=s;
				printf("%d\n",parent->data);
			}
		}
		i++;			
	}//end:while 1#

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
	BSTree T=NULL;
	int n=0;
	int i=0;
	while(scanf("%d",&n)!=EOF)
	{	
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		createBST(&T,data,n);	
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