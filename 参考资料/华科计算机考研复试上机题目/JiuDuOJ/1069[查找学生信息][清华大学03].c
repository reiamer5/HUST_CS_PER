#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int Status;
typedef int Boolean;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define IDLENGTH 50
#define NAMELENGTH 100
#define SEXLENGTH 3
/************************************题目描述*****************************
题目1069：查找学生信息
时间限制：1 秒内存限制：32 兆特殊判题：否提交：9978解决：2658
题目描述：
 输入N个学生的信息，然后进行查询。
输入：
 输入的第一行为N，即学生的个数(N<=1000)
接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
02
03
01
04
输出：
 输出M行，每行包括一个对应于查询的学生的信息。
如果没有对应的学生信息，则输出“No Answer!”
样例输入：
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03
样例输出：
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19
来源：
2003年清华大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7793-1-1.html

**************************************************************************/
typedef struct StuNode
{
    char ID[IDLENGTH];
    char name[NAMELENGTH];
    char sex[SEXLENGTH];
    int age;
    struct StuNode *next;
}StuNode,*StuList;

Status initList(StuList* L)
{
    *L=(StuNode*)malloc(sizeof(StuNode));
    if(*L==NULL)
    {
        printf("Malloc failed!\n");
        return ERROR;
    }
    (*L)->next=NULL;
    return OK;
}
Status destroyList(StuList* L)
{
    StuNode* p=*L;
    while((*L)!=NULL)
    {
        p=*L;
        *L=(*L)->next;
        free(p);
    }
    *L=NULL;
    return OK;
}
Status insert(StuList *L,StuNode data)
{
    StuNode *p=(StuNode*)malloc(sizeof(StuNode));
    if(p==NULL)
    {
        printf("Malloc failed!\n");
        return ERROR;
    }

    strcpy(p->ID,data.ID);
    strcpy(p->name,data.name);
    strcpy(p->sex,data.sex);
    p->age=data.age;

    p->next=(*L)->next;
    (*L)->next=p;

    return OK;
}

StuNode * search(StuList L,char ID[IDLENGTH])
{
    StuNode *p=L->next;

    while(p!=NULL)
    {
        if(strcmp(ID,p->ID)!=0)
        {
            p=p->next;
        }
        else
        {
            return p;
        }
    }
    return p;
}

Status service()
{
    int m=0,n=0;
    int i=0;
    StuNode stu;
    StuNode *p=NULL;
    StuList L;
    initList(&L);
    char ID[IDLENGTH];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s %s %d",stu.ID,stu.name,stu.sex,&stu.age);
        insert(&L,stu);
    }

    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",ID);
        p=search(L,ID);
        if(p!=NULL)
        {
            printf("%s %s %s %d\n",p->ID,p->name,p->sex,p->age);
        }
        else
        {
            printf("No Answer!\n");
        }
    }
    destroyList(&L);
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
