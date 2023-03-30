#include<stdio.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 10000

/*************************题目说明********************/
/*
题目1073：杨辉三角形
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3289解决：1425
题目描述：
输入n值，使用递归函数，求杨辉三角形中各个位置上的值。
输入：
一个大于等于2的整型数n
输出：
题目可能有多组不同的测试数据，对于每组输入数据，
按题目的要求输出相应输入n的杨辉三角形。
样例输入：
6
样例输出：
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/

//递归求解(i,j)位置上的杨辉三角的数值
int handleFunction(int i,int j)
{
	if(j==0||(i+1)==j)
		return 1;
	return handleFunction(i-1,j-1)+handleFunction(i-1,j);
	 
}

Status yanghui(int n)
{
	int data[N];
	int i=0,j=0,k=0;
	data[0]=data[1]=1;

	for(i=2;i<=n;i++)
	{
		data[0]=data[i-1]=1;
		for(j=i-2;j>=1;j--)
		{
			data[j]=data[j]+data[j-1];
		}
		for(k=0;k<i-1;k++)
		{
			printf("%d ",data[k]);
		}
		printf("%d\n",data[k]);
	}

	return OK;

}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		yanghui(n);
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