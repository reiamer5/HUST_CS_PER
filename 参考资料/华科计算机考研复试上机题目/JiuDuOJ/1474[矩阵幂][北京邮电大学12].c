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

//#define M 1000
#define N 20

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1474：矩阵幂
时间限制：1 秒内存限制：128 兆特殊判题：否提交：2823解决：1100
题目描述：
给定一个n*n的矩阵，求该矩阵的k次幂，即P^k。
输入：
输入包含多组测试数据。
数据的第一行为一个整数T(0<T<=10)，表示要求矩阵的个数。
接下来有T组测试数据，每组数据格式如下： 
第一行：两个整数n（2<=n<=10）、k（1<=k<=5），两个数字之间用一个空格隔开，含义如上所示。
接下来有n行，每行n个正整数，其中，第i行第j个整数表示矩阵中第i行第j列的矩阵元素Pij且（0<=Pij<=10）。另外，数据保证最后结果不会超过10^8。
输出：
对于每组测试数据，输出其结果。格式为：
n行n列个整数，每行数之间用空格隔开，注意，每行最后一个数后面不应该有多余的空格。
样例输入：
3
2 2
9 8
9 3
3 3
4 8 4
9 3 0
3 5 7
5 2
4 0 3 0 1
0 0 5 8 5
8 9 8 5 3
9 6 1 7 8
7 2 5 7 3
样例输出：
153 96
108 81
1216 1248 708
1089 927 504
1161 1151 739
47 29 41 22 16
147 103 73 116 94
162 108 153 168 126
163 67 112 158 122
152 93 93 111 97
来源：
2012年北京邮电大学计算机研究生机试真题
*/

int matrix[N][N];
Status multiply(int matrix[N][N],int size,int k)
{
	int cpyMatrix[N][N];//暂存matrix中的数据
	int rsMatrix[N][N];//暂存matrix中的数据
	int i=0,j=0,t=0;
	int count=2;
	int sum=0;

	if(k==1)
		return OK;
	for(i=0;i<size;i++)//复制matrix中的数据到cpyMatrix中
	{
		for(j=0;j<size;j++)
		{
			cpyMatrix[i][j]=matrix[i][j];
		}
	}

	//矩阵乘法
	while(k>=count)//while 1#
	{
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				sum=0;
				for(t=0;t<size;t++)
				{
					sum+=cpyMatrix[i][t]*cpyMatrix[t][j];
				}
				rsMatrix[i][j]=sum;
			}
		}

		count=count<<1;//count*2

		for(i=0;i<size;i++)//复制cpyMatrix中的数据到rsMatrix中
		{
			for(j=0;j<size;j++)
			{
				cpyMatrix[i][j]=rsMatrix[i][j];
			}
		}
	}//end:while 1#

	if(k%2==1)//奇数次乘法  处理最后一次乘法
	{
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				sum=0;
				for(t=0;t<size;t++)
				{
					sum+=cpyMatrix[i][t]*matrix[t][j];
				}
				rsMatrix[i][j]=sum;
			}
		}
	}

	for(i=0;i<size;i++)//复制cpyMatrix中的数据到matrix中
	{
		for(j=0;j<size;j++)
		{
			matrix[i][j]=rsMatrix[i][j];
		}
	}
	
	return OK;
}
Status printMatrix(int matrix[N][N],int size)
{
	int i=0,j=0;
	for(i=0;i<size;i++)//复制matrix中的数据到cpyMatrix中
	{
		for(j=0;j<size-1;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("%d\n",matrix[i][j]);
	}
	return OK;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0,t=0;
	int p=0,k=0;
	int matrix[N][N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(t=0;t<n;t++)
		{
			scanf("%d %d",&p,&k);
			for(i=0;i<p;i++)
			{
				for(j=0;j<p;j++)
				{
					scanf("%d",*(matrix+i)+j);
				}
			}
		//	printMatrix(matrix,p);
			multiply(matrix,p,k);
			printMatrix(matrix,p);
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