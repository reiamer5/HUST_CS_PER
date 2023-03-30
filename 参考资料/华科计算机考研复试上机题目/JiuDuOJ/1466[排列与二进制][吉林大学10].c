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
题目1466：排列与二进制
时间限制：1 秒内存限制：128 兆特殊判题：否提交：832解决：373
题目描述：
在组合数学中，我们学过排列数。从n个不同元素中取出m（m<=n）个元素的所有排列的个数，叫做从n中取m的排列数，记为p(n, m)。
具体计算方法为p(n, m)=n(n-1)(n-2)……(n-m+1)= n!/(n-m)! (规定0!=1).当n和m不是很小时，这个排列数是比较大的数值，
比如  p(10,5)=30240。如果用二进制表示为p(10,5)=30240=( 111011000100000)b，也就是说，最后面有5个零。我们的问题就是，
给定一个排列数，算出其二进制表示的后面有多少个连续的零。
输入：
输入包含多组测试数据，每组测试数据一行。
每行两个整数，n和m，0<m<=n<=10000，n=0标志输入结束，该组数据不用处理。
输出：
对于每个输入，输出排列数p(n, m)的二进制表示后面有多少个连续的零。每个输出放在一行。
样例输入：
10 5
6 1
0 0
样例输出：
5
1
*/
int pnm(int n,int m)
{
	int limit=n-m+1;
	int sum=n;
	n--;
	while(n>=limit)
	{
		sum*=n;
		n--;
	}
	return sum;
}
int countTailZero(int n)
{
	int count=0;
	while(n%2==0)
	{
		count++;
		n/=2;
	}
	return count;
}

int all(int n,int m)
{
	int limit=n-m+1;
	int count=0;
	int temp=0;
	while(n>=limit)
	{
		temp=n;
		while(temp%2==0)
		{
			count++;
			temp/=2;
		}
		n--;
	}
	return count;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0,m=0;

	scanf("%d %d",&n,&m);
	while(n)//while 1#
	{
		printf("%d\n",all(n,m));
		scanf("%d %d",&n,&m);
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