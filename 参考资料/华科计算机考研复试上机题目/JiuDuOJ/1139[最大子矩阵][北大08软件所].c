#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 110
const int MAXINT=((unsigned int)-1)>>1;
const int MININT=~(((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1139：最大子矩阵
时间限制：1 秒内存限制：32 兆特殊判题：否提交：902解决：323
题目描述：
已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
比如，如下4 * 4的矩阵

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

的最大子矩阵是

9 2
-4 1
-1 8

这个子矩阵的大小是15。
输入：
输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。
再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，整数之间由空白字符分隔（空格或者空行）。
已知矩阵中整数的范围都在[-127, 127]。
输出：
测试数据可能有多组，对于每组测试数据，输出最大子矩阵的大小。
样例输入：
4
0 -2 -7 0
9 2 -6 2
-4 1 -4  1
-1 8  0 -2
样例输出：
15
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7862-1-1.html
*/

int matrixSum[N][N][N];//matrixSum[i][j][k]表示第i行元素第j列元素到第k列元素的和
/*
动态规划解决最大字段和问题

*/
int maxSubSum(int data[N],int size)
{
	int maxSum=MININT;//当前求得的最大字段和
	int thisSum=0;
	//到当前位置,所有元素的和,若到某一位置thisSum<0,则从该位置开始重新累计计算
	int i=0,j=0;

	for(j=0;j<size;j++)//for 1#
	{
		if(thisSum>=0)
		{
			thisSum=thisSum+data[j];
		}
		else
		{
			thisSum=data[j];
		}		
		if(thisSum>maxSum)
		{//新的最大子段和 坐标区间
			maxSum=thisSum;
		}	
	}//end:for 1#
	return maxSum;
}

int maxSummatrix(int matrix[N][N],int size)
{
	int i=0,j=0,k=0;
	int maxSum=MININT,sum=0;
	int data[N];

	for(i=0;i<size;i++)//for 1#
	{
		for(j=0;j<size;j++)//for 2#	
		{
			//第i行元素第j列元素到第k列元素的和
			matrixSum[i][j][j]=matrix[i][j];
			for(k=j+1;k<size;k++)//for 3#
			{
				matrixSum[i][j][k]=	matrixSum[i][j][k-1]+matrix[i][k];
			}//end:for 3#
		}//end:for 2#
	}//end:for 1#

	for(i=0;i<size;i++)//for 1#
	{
		for(j=i;j<size;j++)//for 2#	
		{
			for(k=0;k<size;k++)//for 3#
			{
				data[k]=matrixSum[k][i][j];
			}//end:for 3#
			sum=maxSubSum(data,size);
			if(sum>maxSum)
				maxSum=sum;
		}//end:for 2#
	}//end:for 1#

	return maxSum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int size=0;
	int i=0,j=0;
	int matrix[N][N];
	while(scanf("%d",&size)!=EOF)//while 1#
	{
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				scanf("%d",*(matrix+i)+j);
			}	
		}	
		printf("%d\n",maxSummatrix(matrix,size));
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