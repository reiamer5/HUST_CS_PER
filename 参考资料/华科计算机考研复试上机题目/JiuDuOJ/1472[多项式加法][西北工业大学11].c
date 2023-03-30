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

#define N 2500
#define OFFSET 1000

/*************************题目说明********************/
/*
题目1472：求两个多项式的和
时间限制：1 秒内存限制：128 兆特殊判题：否提交：1356解决：247
题目描述：
输入两个多项式，计算它们的和。
每个多项式有若干对整数表示，每组整数中，第一个整数表示系数（非0），第二个整数表示该项的次数。
如由3 3 5 -2 1 4 0表示3x^5 - 2 * x + 4其中第一个3表示该多项式由三个整数对表示。
输入：
输入为两行，分别表示两个多项式。表示每项的整数对按照次数大小降序给出。(次数绝对值小于1000，系数绝对值小于10000)
输出：
按照降次顺序输出表示和多项式的整数对（系数为0的整数对不用输出，整数对由空格分隔，最后一个整数对后不添加空格）
样例输入：
3 3 5 -2 1 4 0
4 2 3 -1 2 1 1 3 0
样例输出：
3 5 2 3 -1 2 -1 1 7 0
来源：
2011年西北工业大学计算机研究生机试真题
*/


int A[N],B[N],C[N];
//多项式加法

Status add( )
{
	int i=0,count=0;
	for(i=0;i<N;i++)
	{
		C[i]=A[i]+B[i];
	}

	for(i=N-1;i>=0;i--)
	{
		if(C[i]!=0)
			count++;
	}
	for(i=N-1;i>=0&&count>1;i--)
	{
		if(C[i]!=0)
		{
			printf("%d %d ",C[i],i-OFFSET);
			count--;
		}
	}

	while(i>=0)
	{
		if(C[i]!=0)
		{
			printf("%d %d\n",C[i],i-OFFSET);
		}
		i--;
	}

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n1=0,n2=0;
	int i=0,j=0;
	int p=0,e=0;
	while(scanf("%d",&n1)!=EOF)//while 1#
	{
		for(i=0;i<N;i++)
		{
			A[i]=B[i]=C[i]=0;
		}

		for(i=0;i<n1;i++)
		{
			scanf("%d %d",&p,&e);
			A[e+OFFSET]=p;
		}

		scanf("%d",&n2);

		for(i=0;i<n2;i++)
		{
			scanf("%d %d",&p,&e);
			B[e+OFFSET]=p;
		}

		add();
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