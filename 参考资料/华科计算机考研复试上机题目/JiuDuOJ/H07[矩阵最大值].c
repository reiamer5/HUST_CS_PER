#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define M 256
#define N 256
#define MININT -32768
typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
编写一个程序输入一个mXn的矩阵存储并输出，并且求出每行的最大值和每行的总和。
要求把每行总和放入每行最大值的位置，如果有多个最大值，取下标值最小的那一个作为最大值。
最后将结果矩阵输出。
输入：
输入的第一行包括两个整数m和n(1<=m,n<=100)，分别代表矩阵的行和列的维数。
接下来的m行每行有n个数，代表矩阵的元素。
输出：
可能有多组测试数据，对于每组数据，输出按题目要求执行后的矩阵。
样例输入：
3 3
1 1 1
1 1 1
1 1 1
3 3
3 2 3
2 3 2
3 2 3
样例输出：
3 1 1
3 1 1
3 1 1
8 2 3
2 7 2
8 2 3

*/


Status maxAndSum(ElemType matrix[M][N],int m,int n)
{
	int i=0,j=0;
	int sum=0;
	int maxValue=MININT;
	int maxIndex=0;

	for(i=0;i<m;i++)//for 1#
	{
		sum=0;
		maxValue=MININT;
		maxIndex=0;

		for(j=0;j<n;j++)//for 2#
		{
			if(matrix[i][j]>maxValue)
			{
				maxValue=matrix[i][j];
				maxIndex=j;
			}
			sum+=matrix[i][j];
		}//end:for 2#

		matrix[i][maxIndex]=sum;
	}//end:for 1#
	
	for(i=0;i<m;i++)//for 1#
	{
		for(j=0;j<n-1;j++)//for 2#
		{
			printf("%d ",matrix[i][j]);
		}//end:for 2#

		printf("%d\n",matrix[i][j]);
	}//end:for 1#

	return OK;
}



//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	ElemType matrix[M][N];
	int m=0,n=0;
	int i=0,j=0;
	while(scanf("%d %d",&m,&n)!=EOF)
	{

		for(i=0;i<m;i++)//for 1#
		{
			for(j=0;j<n;j++)//for 2#
			{
				scanf("%d",*(matrix+i)+j);
			}//end:for 2#
		}//end:for 1#
		maxAndSum(matrix,m,n);
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