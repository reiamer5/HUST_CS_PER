#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 100

const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*

题目1470：调整方阵
时间限制：1 秒内存限制：128 兆特殊判题：否提交：1679解决：685
题目描述：
输入一个N（N<=10）阶方阵，按照如下方式调整方阵：
1.将第一列中最大数所在的行与第一行对调。
2.将第二列中从第二行到第N行最大数所在的行与第二行对调。
依此类推...
N-1.将第N-1列中从第N-1行到第N行最大数所在的行与第N-1行对调。
N.输出这个方阵
输入：
包含多组测试数据,每组测试数据第一行为一个整数N,表示方阵的阶数.
接下来输入这个N阶方阵.
输出：
调整后的方阵
样例输入：
4
3 6 8 7
6 7 5 3
8 6 5 3
9 8 7 2
样例输出：
9 8 7 2
6 7 5 3
3 6 8 7
8 6 5 3
来源：
2011年西北工业大学计算机研究生机试真题

*/
//交换矩阵中的两行
int exchangeRows(int matrix[N][N],int rowa,int rowb,int n)
{
	int temp=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		temp=matrix[rowa][i];
		matrix[rowa][i]=matrix[rowb][i];
		matrix[rowb][i]=temp;
	}
	return 0;
}
Status adjust(int matrix[N][N],int n)
{
	int i=0,j=0;
	int max=MININT;
	int maxRowIndex=0;

	for(i=0;i<n;i++)
	{
		max=-MININT;
		for(j=i;j<n;j++)
		{
			if(matrix[j][i]>max)
			{
				max=matrix[j][i];
				maxRowIndex=j;
			}
		}
		//列中最大数所在的行与对应行对调
		exchangeRows(matrix,i,maxRowIndex,n);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	int matrix[N][N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",*(matrix+i)+j);
			}
		}
		adjust(matrix,n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				printf("%d ",matrix[i][j]);
			}
			printf("%d\n",matrix[i][j]);
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