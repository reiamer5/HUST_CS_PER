#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define N 30

typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
职工有职工号，姓名，年龄.输入n个职工的信息，找出3个年龄最小的职工打印出来。
输入：
输入第一行包括1个整数N，1<=N<=30，代表输入数据的个数。
接下来的N行有N个职工的信息：
包括职工号(整数)， 姓名(字符串，长度不超过10)， 年龄(1<=age<=100)。
输出：
可能有多组测试数据，对于每组数据，
输出结果行数为N和3的较小值，分别为年龄最小的职工的信息。
关键字顺序：年龄>工号>姓名，从小到大。
样例输入：
5
501 Jack 6
102 Nathon 100
599 Lily 79
923 Lucy 15
814 Mickle 65
样例输出：
501 Jack 6
923 Lucy 15
814 Mickle 65

*/


//定义表示职工信息的节点
typedef struct employee
{
	int id;
	char name[10];
	int age;
}employee,Employees[N];

int comp(const void *a,const void *b)
{
	int dage= (*(employee *)a).age-(*(employee *)b).age;	
	int did=(*(employee *)a).id-(*(employee *)b).id;
	int dname=strcmp((*(employee *)a).name,(*(employee *)b).name);

	if(dage==0)
	{
		if(did==0)
		{
			return dname;
		}
		else
		{
			return did;
		}
	}
	else
	{
		return dage;
	}
}



//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int i=0;
	Employees ems;
	int id,age;
	char name[10];
	int n=0;

	while(scanf("%d",&n) != EOF)
	{
		i=0;
		while(i<n)
		{
			scanf("%d %s %d",&id,name,&age);
			ems[i].id=id;
			strcpy(ems[i].name,name);
			ems[i].age=age;
			i++;
		}

		qsort(ems,n,sizeof(employee),comp);

		for(i=0;i<3&&i<n;i++)
		{
			printf("%d %s %d\n",ems[i].id,ems[i].name,ems[i].age);
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