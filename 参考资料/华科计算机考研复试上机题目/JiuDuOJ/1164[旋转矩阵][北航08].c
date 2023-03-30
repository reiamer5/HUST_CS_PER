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

typedef int ElemType;

//#define M 1000
#define N 9

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1164：旋转矩阵
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2757解决：1072
题目描述：
任意输入两个9阶以下矩阵，要求判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。
要求先输入矩阵阶数，然后输入两个矩阵，每行两个数之间可以用任意个空格分隔。行之间用回车分隔，两个矩阵间用任意的回车分隔。
输入：
输入有多组数据。
每组数据第一行输入n(1<=n<=9)，从第二行开始输入两个n阶矩阵。
输出：
判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。
如果旋转角度的结果有多个，则输出最小的那个。
样例输入：
3
1 2 3
4 5 6
7 8 9
7 4 1
8 5 2
9 6 3
样例输出：
90
来源：
2008年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7887-1-1.html
*/

//将矩阵matrix旋转arc度后存放于rMatrix中
Status rotate(int matrix[N][N],int rMatrix[N][N],int n,int arc)
{
	int i1=0,j1=0;
	int i2=0,j2=0;
	if(arc==0||arc%360==0)//旋转0
	{
		for(i1=0;i1<n;i1++)
		{
			for(j1=0;j1<n;j1++)
			{
				rMatrix[i1][j1]=matrix[i1][j1];
			}
		}
	}
	else if(arc==90)
	{
		for(i1=0,j2=0;i1<n&&j2<n;i1++,j2++)
		{
			for(j1=0,i2=n-1;j1<n&&i2>-1;j1++,i2--)
			{
				rMatrix[i1][j1]=matrix[i2][j2];
			}
		}

	}
	else if(arc==180)
	{
		for(i1=0,i2=n-1;i1<n&&i2>-1;i1++,i2--)
		{
			for(j1=0,j2=n-1;j1<n&&j2>-1;j1++,j2--)
			{
				rMatrix[i1][j1]=matrix[i2][j2];
			}
		}

	}
	else if(arc==270)
	{
		for(i1=0,j2=n-1;i1<n&&j2>-1;i1++,j2--)
		{
			for(j1=0,i2=0;j1<n&&i2<n;j1++,i2++)
			{
				rMatrix[i1][j1]=matrix[i2][j2];
			}
		}

	}
	return OK;
}

Status printMatrix(int matrix[N][N],int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("%d\n",matrix[i][j]);
	}
	return OK;
}

Boolean equal(int matrix[N][N],int rMatrix[N][N],int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(matrix[i][j]!=rMatrix[i][j])
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	int matrix1[N][N],matrix2[N][N],rMatrix[N][N];
	Boolean flag=FALSE;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&matrix1[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&matrix2[i][j]);
			}
		}

		flag=FALSE;

		if(TRUE==equal(matrix1,matrix2,n))
		{
			printf("0\n");
			flag=TRUE;
		}

		rotate(matrix1,rMatrix,n,90);
	//	printMatrix(rMatrix,n);
		if(FALSE==flag&&TRUE==equal(rMatrix,matrix2,n))
		{
			printf("90\n");
			flag=TRUE;
		}

		rotate(matrix1,rMatrix,n,180);
	//	printMatrix(rMatrix,n);
		if(FALSE==flag&&TRUE==equal(rMatrix,matrix2,n))
		{
			printf("180\n");
			flag=TRUE;
		}

		rotate(matrix1,rMatrix,n,270);
	//	printMatrix(rMatrix,n);
		if(FALSE==flag&&TRUE==equal(rMatrix,matrix2,n))
		{
			printf("270\n");
			flag=TRUE;
		}
		if(FALSE==flag)
			printf("-1\n");
	
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