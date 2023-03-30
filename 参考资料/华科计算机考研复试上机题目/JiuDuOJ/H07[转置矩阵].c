#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define N 100

typedef int Status;
typedef int Boolean;
/*
题目描述：
输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就地逆置)。
输入：
输入的第一行包括一个整数N,(1<=N<=100)，代表矩阵的维数。
接下来的N行每行有N个整数，分别代表矩阵的元素。
输出：
可能有多组测试数据，对于每组数据，将输入的矩阵转置后输出。
样例输入：
3
1 2 3
4 5 6
7 8 9
样例输出：
1 4 7
2 5 8
3 6 9

*/
Status transpose(int matrix[N][N],int n)
{
	int i=0,j=0;
	int temp;
	for(i=0;i<n;i++)//for 1#
	{
		for(j=i+1;j<n;j++)//for 2#
		{

			temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
		}//end:for 2#
	}//end:for 1#

	for(i=0;i<n;i++)//for 1#
	{
		for(j=0;j<n-1;j++)//for 2#
		{
			printf("%d ",matrix[i][j]);
		}//end:for 2#

		printf("%d\n",matrix[i][j]);
	}//end:for 1#
	return TRUE;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int matrix[N][N];
	int i=0,j=0;

	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)//for 1#
		{
			for(j=0;j<n;j++)//for 2#
			{
				scanf("%d",&matrix[i][j]);
			}//end:for 2#
		}//end:for 1#

		transpose(matrix,n);
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