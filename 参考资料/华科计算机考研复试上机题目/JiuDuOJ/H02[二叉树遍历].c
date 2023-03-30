#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 100
typedef char ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
例如如下的先序遍历字符串：
ABC##DE#G##F###
其中"#"表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
输入：
输入包括1行字符串，长度n不超过100。
输出：
可能有多组测试数据，对于每组数据，
输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。
样例输入：
abc##de#g##f###
样例输出：
c b e g d f a 

*/
//定义二叉树节点
typedef struct BTNode
{
	ElemType data;
	struct BTNode *lchild,*rchild;
}BTNode,*BTree;

//根据str中的字符串先序建立二叉树
Status createTreePreOrder(BTree*T,ElemType str[N],int *i)
{
	if(str[*i]!='\0')
	{
		if(str[*i]=='#')
		{
			*T=NULL;
			(*i)++;
			return OK;
		}
		else 
		{
			*T=(BTNode *)malloc(sizeof(BTNode));
			if(*T==NULL)
				return ERROR;
			(*T)->data=str[*i];
			(*i)++;	
			if( createTreePreOrder(&((*T)->lchild),str,i)==OK )
				if( createTreePreOrder(&((*T)->rchild),str,i)==OK )
					return OK;
		}
	}
	return OK;
}
//中序遍历二叉树
Status inOrderTraverse(BTree T,ElemType printStr[N],int *j)
{
	if(T->lchild!=NULL)
	{
		inOrderTraverse(T->lchild,printStr,j);
	}
	if(T!=NULL)
	{
		//printf("%c",T->data);
		printStr[*j]=T->data;
		(*j)++;	
	}
	if(T->rchild!=NULL)
	{
		inOrderTraverse(T->rchild,printStr,j);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	ElemType str[N];
	ElemType printStr[N];
	BTree T;
	int i=0;
	int j=0;
	int k=0;
	while(gets(str)!=NULL)
	{	
		if(strlen(str)>0)
		{
			i=0;
			createTreePreOrder(&T,str,&i);	
			inOrderTraverse(T,printStr,&j);
			for(k=0;k<j-1;k++)
			{
				printf("%c ",printStr[k]);
			}
			printf("%c\n",printStr[k]);
			str[0]='\0';
			j=0;
		}
		
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