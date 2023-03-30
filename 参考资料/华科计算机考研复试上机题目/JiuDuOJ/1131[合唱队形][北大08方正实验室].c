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
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1131：合唱队形
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2216解决：686
题目描述：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，
则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入：
输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
输出：
可能包括多组测试数据，对于每组数据，
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
样例输入：
8
186 186 150 200 160 130 197 220
样例输出：
4
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7854-1-1.html
九度Online Judge修改自HUSTOJ | 浙ICP备09099636号 | 九度Online Judge版权所有
*/
int bt[N];	
int lt[N];
//求最大上升子序列数:startIndex~endIndex
Status maxAscSub(int data[N],int startIndex,int endIndex)
{	
	int next[N];
	int i=0,j=0;
	int btN=0,nextP=-1;
	int sum=0,max=0;
	for(i=startIndex;i<=endIndex;i++)
	{
		bt[i]=1;
		next[i]=-1;
	}

	for(i=startIndex+1;i<=endIndex;i++)
	{
		btN=0;
		nextP=-1;
		for(j=i-1;j>=startIndex;j--)
		{
			if(data[i]>data[j]&&bt[j]>btN)
			{
				nextP=j;
				btN=bt[j];
			}
		}
		if(nextP!=-1)
		{
			bt[i]=btN+1;
			next[i]=nextP;
		}		
	}
	return OK;
}

//求最大下降子序列数:startIndex~endIndex
Status maxDescSub(int data[N],int startIndex,int endIndex)
{
	int next[N];
	int i=0,j=0;
	int ltN=0,nextP=-1;
	int sum=0,max=0;
	for(i=startIndex;i<=endIndex;i++)
	{
		lt[i]=1;
		next[i]=-1;
	}

	for(i=endIndex-1;i>=startIndex;i--)
	{
		ltN=0;
		nextP=-1;
		for(j=i+1;j<=endIndex;j++)
		{
			if(data[i]>data[j]&&lt[j]>ltN)
			{
				nextP=j;
				ltN=lt[j];
			}
		}
		if(nextP!=-1)
		{
			lt[i]=ltN+1;
			next[i]=nextP;
		}
		
	}
	return OK;
}
int handleFunction(int data[N],int size)
{
	int i=1;
	int num=0;
	int min=size;

	maxAscSub(data,0,size-1);
	maxDescSub(data,0,size-1);

	for(i=0;i<size;i++)
	{
		num=size+1-bt[i]-lt[i];
		if(num<min)
			min=num;
	}
	return min;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	int data[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		printf("%d\n",handleFunction(data,n));
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