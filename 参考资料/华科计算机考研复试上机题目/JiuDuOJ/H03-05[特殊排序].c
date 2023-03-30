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
输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。
输入：
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
接下来的一行有N个整数。
输出：
可能有多组测试数据，对于每组数据，
第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
第二行将排序的结果输出。
样例输入：
4
1 3 4 2
样例输出：
4
1 2 3
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
		if(n==1)
		{
			printf("%d\n%d",data[0],-1);
		}
		else
		{
			qsort(data,n,sizeof(ElemType),comp);

			printf("%d\n",data[n-1]);

			for(i=0;i<n-2;i++)
			{
				printf("%d ",data[i]);
			}
			printf("%d\n",data[i]);
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