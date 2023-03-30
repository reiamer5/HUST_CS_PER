#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
//#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MININT -32768

typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目1200：最大的两个数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2566解决：661
题目描述：
    输入一个四行五列的矩阵，找出每列最大的两个数。
输入：
    输入第一行包括一个整数n(1<=n<=1000)，接下来的四行每行包括五个整数。代表一个四行五列的矩阵，矩阵元素全部是整数。
输出：
    可能有多组测试数据，对于每组数据，按照样例输出的格式将每列最大的两个数输出，如果最大的两个数中的一个数在这一列中有多个相同的值，则行值取行值小的那一个。
    输出时要保留原矩阵的行列顺序，即在原矩阵中行值小的，在输出矩阵中的行值依然小。
样例输入：
1
1  2   4  9  8
-1  4  9  8  8
12  9  8  7  0
7   8  9  7  0
样例输出：
12 9 9 9 8 
7 8 9 8 8 
提示：
每个数字后面都要输出一个空格

*/

Status searchMax(int data[4][5])
{
	int i=0,j=0; 
	int maxs[5][2];
	for(j=0;j<5;j++)//for #1
	{
		maxs[j][0]=maxs[j][1]=MININT;
		for(i=0;i<4;i++)//end:for #2
		{	
			if(data[i][j]>maxs[j][0]&&data[i][j]>maxs[j][1])
			{
				if(maxs[j][1]>maxs[j][0])
				{
					maxs[j][0]=maxs[j][1];	
					maxs[j][1]=data[i][j];
				}
				else if(maxs[j][1]==maxs[j][0]&&maxs[j][1]==MININT)
				{
					maxs[j][0]=data[i][j];
				}
				else
				{
					maxs[j][1]=data[i][j];
				}
			}
			else if(data[i][j]>maxs[j][0]||data[i][j]>maxs[j][1])
			{
				if(data[i][j]>maxs[j][0])
				{
					maxs[j][0]=maxs[j][1];
					maxs[j][1]=data[i][j];
				}
				else //if(data[i][j]>maxs[j][1])
				{
					maxs[j][1]=data[i][j];
				}
			}
			
			//printf("%d ",data[i][j]);
		
		}//end:for #2	
	}//end:for #1

	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",maxs[j][i]);
		}
		//printf("%d\n",maxs[j][i]);
	}
	return OK;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int data[4][5];
	int n=0;
	int i=0,j=0;
	scanf("%d",&n);
	while(n>0)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<5;j++)
			{
				scanf("%d",&data[i][j]);
			}
		}

		searchMax(data);
		n--;
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