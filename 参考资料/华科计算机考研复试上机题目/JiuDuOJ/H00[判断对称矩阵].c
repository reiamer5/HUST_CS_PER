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
输入一个N维矩阵，判断是否对称。
输入：
输入第一行包括一个数：N(1<=N<=100)，表示矩阵的维数。
接下来的N行，每行包括N个数，表示N*N矩阵的元素。
输出：
可能有多组测试数据，对于每组数据，
输出"Yes!”表示矩阵为对称矩阵。
输出"No!”表示矩阵不是对称矩阵。
样例输入：
4
16 19 16 6 
19 16 14 5 
16 14 16 3 
6 5 3 16 
2
1 2
3 4
样例输出：
Yes!
No! 
*/

/*
n:矩阵为n*n
matrix:矩阵数据
如果是对称矩阵返回TRUE 否则返回FALSE
*/
Status symmetry(int n,int matrix[N][N])
{
	int i=0,j=0;
	for(i=0;i<n;i++)//for 1#
	{
		for(j=i+1;j<n;j++)//for 2#
		{
			if(matrix[i][j]!=matrix[j][i])
				return FALSE;
		}//end:for 2#
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

		if(TRUE==symmetry(n,matrix))
		{
			printf("Yes!\n");
		}
		else
		{
			printf("No!\n");
		}
			

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