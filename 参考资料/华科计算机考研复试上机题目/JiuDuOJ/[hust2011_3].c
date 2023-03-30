#include<stdio.h>
#include<malloc.h>
typedef int Status;
typedef int Boolean;
typedef char ElemType;
#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5
typedef struct BTNode
{
	ElemType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode,*BTree;

Status initTree(BTree * T)
{
	*T=NULL;
	return OK;
}

Status distroyTree(BTree * T)
{
	if(*T!=NULL)
	{
		distroyTree(&((*T)->lchild));
		distroyTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
	return OK;
}

Status preOderTraverse(BTree T)
{
	if(T!=NULL)
	{
		printf("%c ",T->data);
	}
	if(T->lchild!=NULL)
	{
		preOderTraverse(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		preOderTraverse(T->rchild);
	}

	return OK;
}
Status insert(BTree * T,ElemType e)
{
	BTNode *p=NULL;
	BTNode *current=*T;
	BTNode *parent=NULL;

	while(current!=NULL)//while 1#
	{
		parent=current;
		if(current->data>e)
		{
			current=current->lchild;
		}
		else if(current->data<e)
		{
			current=current->rchild;
		}
		else
		{
			return OK;
		}
	}//end:while1#

	p=(BTNode *)malloc(sizeof(BTNode));
	if(p==NULL)
	{
		printf("malloc error!\n");
		return ERROR;
	}
	p->data=e;
	p->lchild=p->rchild=NULL;
	if(*T==NULL)
	{
		*T=p;
		return OK;
	}

	if(parent->data>e)
	{
		parent->lchild=p;
	}
	else
	{
		parent->rchild=p;
	}

	return OK;
}
Status service()
{
	char *str=NULL;
	int size=MAXSIZE;
	int num=0;
	char c;
	BTree T=NULL;
	int i=0;
	str=(char *)malloc(MAXSIZE*sizeof(char));
	while((c=getchar())!=EOF)//while
	{
		str[num++]=c;
		if(num==size)
		{
			size+=MAXSIZE;
			str=realloc(str,size);
			if(str==NULL)
			{
				printf("malloc error!\n");
				return ERROR;
			}
		}
	}//end:while 1#

	str=realloc(str,num);
	if(str==NULL)
	{
		printf("malloc error!\n");
		return ERROR;
	}
	initTree(&T);
	while(i<num)
	{
		insert(&T,str[i]);
		i++;
	}

	preOderTraverse(T);
	distroyTree(&T);

	return OK;
}

int main()
{
	if(ERROR==service())
	{
		printf("ERROR!\n");
		return ERROR;
	}
	return OK;
}