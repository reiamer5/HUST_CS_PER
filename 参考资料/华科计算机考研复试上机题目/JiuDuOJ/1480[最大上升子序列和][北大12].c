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
#define N 1200

//const int MAXINT =((unsigned int)-1)>>1;
const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1480：最大上升子序列和
时间限制：1 秒内存限制：128 兆特殊判题：否提交：1254解决：480
题目描述：
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ...,aN)，
我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... < iK <= N。比如，
对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中序列和最大为18，为子序列(1, 3, 5, 9)的和.
你的任务，就是对于给定的序列，求出最大上升子序列和。
注意，最长的上升子序列的和不一定是最大的，比如序列(100, 1, 2, 3)的最大上升子序列和为100，而最长上升子序列为(1, 2, 3)。
输入：
输入包含多组测试数据。
每组测试数据由两行组成。第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000（可能重复）。
输出：
对于每组测试数据，输出其最大上升子序列和。
样例输入：
7
1 7 3 5 9 4 8
样例输出：
18
来源：
2012年北京大学计算机研究生机试真题
*/


int maxAscSum(int data[N],int size)
{
	int i=0,j=0,k=0;
	int bn[N];//bn[i]指示data[i]到data[size-1]中最大上升子序列的和
	int next[N];//next[i]记录i在最大上升子序列的后继点
	int nextP=-1;
	int sum=0;
	int maxSum=MININT;

	if(size==1)
		return data[0];
	for(i=0;i<size;i++)
	{
		bn[i]=data[i];
		next[i]=-1;
	}

	for(i=size-2;i>=0;i--)//for 1#
	{
		nextP=-1;
		maxSum=MININT;
		for(j=i+1;j<size;j++)//for 2#
		{
			if(data[i]<data[j])//if 1#
			{
				sum=0;
				for(k=j;k<size&&k!=-1;k=next[k])//for 3#
				{
					sum+=data[k];
				}//end:for 3#
				if(sum>maxSum)
				{
					maxSum=sum;
					nextP=j;
				}			
			}//end:if 1#

			if(nextP!=-1)
			{
				bn[i]=maxSum+data[i];
				next[i]=nextP;
			}	
		}//end:for 2#			
	}//end:for 1#

	for(i=0;i<size;i++)
	{
		if(bn[i]>maxSum)
			maxSum=bn[i];
	}
	return maxSum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int size=0;
	int i=0;
	int data[N];
	while(scanf("%d",&size)!=EOF)//while 1#
	{
		for(i=0;i<size;i++)
		{
			scanf("%d",data+i);
		}
		printf("%d\n",maxAscSum(data,size));
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