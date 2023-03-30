#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//#define M 1000
#define N 60

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1060：完数VS盈数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5105解决：1898
题目描述：
一个数如果恰好等于它的各因子(该数本身除外)子和，如：6=3+2+1。则称其为“完数”；若因子之和大于该数，则称其为“盈数”。
求出2到60之间所有“完数”和“盈数”。
输入：
题目没有任何输入。
输出：
输出2到60之间所有“完数”和“盈数”，并以如下形式输出：
E: e1 e2 e3 ......(ei为完数)
G: g1 g2 g3 ......(gi为盈数)
其中两个数之间要有空格，行尾不加空格。
样例输入：
样例输出：
来源：
2000年清华大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7784-1-1.html

*/
Status handleFunction()
{
	int E[60];
	int G[60];
	int eLen=0;
	int gLen=0;
	int i=0,j=0;
	int sum=1;
	int limit=0;

	for(i=2;i<=60;i++)
	{
		limit=i/2;//这里不开方更好	
		sum=1;
		for(j=2;j<=limit;j++)
		{
			if(i%j==0)
			{
				sum+=j;
			}
		}
		if(sum==i)
		{
			E[eLen++]=i;
		}
		else if(sum>i)
		{
			G[gLen++]=i;
		}
	
	}
	printf("E: ");
	for(i=0;i<eLen-1;i++)
	{
		printf("%d ",E[i]);
	}
	printf("%d\n",E[i]);

	printf("G: ");
	for(i=0;i<gLen-1;i++)
	{
		printf("%d ",G[i]);
	}
	printf("%d\n",G[i]);
	

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	handleFunction();
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