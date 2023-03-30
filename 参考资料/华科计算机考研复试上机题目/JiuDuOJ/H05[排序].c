#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 1000
typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
    对输入的n个数进行排序并输出。
输入：
    输入的第一行包括一个整数n(1<=n<=100)。
    接下来的一行包括n个整数。
输出：
    可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
    每组测试数据的结果占一行。
样例输入：
4
1 4 3 2
样例输出：
1 2 3 4 

*/



ElemType data[N];

int comp(const void *a,const void *b)
{
	return  *((int*)a)-*((int*)b);
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
		}
		
		qsort(data,n,sizeof(ElemType),comp);

		for(i=0;i<n;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
	
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