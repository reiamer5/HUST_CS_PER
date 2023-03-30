#include<stdio.h>
//#include<string.h>
#include<malloc.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 5000
/*
题目描述：
生成一个长度为21的数组，依次存入1到21；
建立一个长度为21的单向链表，将上述数组中的数字依次存入链表每个结点中；
将上述链表变为单向封闭(循环)链表；从头结点开始数，将第17个结点删除，将它的下一个结点作为新的头结点；
重复上述过程，直到该链表中只剩一个结点，显示该结点中存入的数字。
输入：
没有任何输入数据。
输出：
输出上面题目描述中最后剩下的节点中存入的数字。
样例输入：
样例输出：
提示：
请不要直接输出数据水过去，这样达不到提升自己的目的，
请按照题目要求来做题，这样到真正考试时才能应对自如。
*/

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;


Status choose()
{
	int i=1;
	LNode *p;
	LinkList L;
	LinkList tail;
	LNode *last,*current;
	int data=0;

	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
	{
		return ERROR;
	}


//	tail->next=L;
	L->data=i;
	L->next=L;//首尾成环
	tail=L;

	while(i<21)
	{
		i++;
		p=(LNode*)malloc(sizeof(LNode));
		if(p==NULL)
		{
			return ERROR;
		}
		p->data=i;
		p->next=tail->next;
		tail->next=p;
		tail=p;		
	}


	i=1;
	last=tail;
	current=L;
	while(current!=last)
	{
		
		if(i==17)
		{
			last->next=current->next;
			p=current;
			
			current=current->next;
			free(p);
			i=1;
		}
		else
		{
			last=current;
			current=current->next;
			i++;
		}
		
	}
	data=current->data;
	printf("%d\n",data);
	free(current);
	return OK;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	return choose();
}

int main()
{
	choose();
	return OK;
}