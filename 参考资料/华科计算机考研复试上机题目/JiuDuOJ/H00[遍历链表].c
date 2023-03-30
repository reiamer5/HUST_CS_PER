#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;
typedef int ElemType;

/*
建立一个升序链表并遍历输出。
输入：
输入的每个案例中第一行包括1个整数：n(1<=n<=1000)，接下来的一行包括n个整数。
输出：
可能有多组测试数据，对于每组数据，
将n个整数建立升序链表，之后遍历链表并输出。
样例输入：
4
3 5 7 9
样例输出：
3 5 7 9
*/

//定义节点
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//初始化链表
Status initList(LinkList*L)
{
	*L=(LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL;
	if(*L==NULL)
		return ERROR;
	return OK;
}
//按升序将data插入到L中
Status insertListAsc(LinkList L,ElemType data)
{
	LNode * p=(LNode*)malloc(sizeof(LNode));
	LNode *q;
	if(L==NULL)
		return ERROR;
	p->data=data;
	q=L;
	while(q->next!=NULL && data>q->next->data)
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;

	return OK;
}

//依次打印链表L中的元素
Status printList(LinkList L)
{
	LNode *p;
	if(NULL==L)
		return ERROR;
	p=L->next;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d",p->data);
	return OK;
}


//销毁链表L
Status destroyList(LinkList*L)
{
	LNode *p;
	if(*L==NULL)
		return ERROR;
	p=*L;
	while(p!=NULL)
	{
		*L=(*L)->next;
		free(p);
		p=*L;
	}
	return OK;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	LinkList L;
	int i=0,j=0;
	int data=0;

	while(scanf("%d",&n)!=EOF)//while 1#
	{
		initList(&L);
		for(i=0;i<n;i++)//for 1#
		{	
			scanf("%d",&data);	
			insertListAsc(L,data);
		}//end:for 1#

		printList(L);
		
		printf("\n");
		destroyList(&L);
	}//end:while 1#

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