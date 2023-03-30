#include<stdio.h>

#define OK 1
#define ERROR 0

typedef int Status;
/*

题目描述：
N阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。（要求采用非递归）
输入：
输入包括一个整数N,(1<=N<90)。
输出：
可能有多组测试数据，对于每组数据，
输出当楼梯阶数是N时的上楼方式个数。
样例输入：
4
样例输出：
5

的多句话，每句话占一行。

*/

long long  f(long long  n)
{
	long long  k=n;
	long long  a=1,b=2;

	if(n==1)
		return 1;
	if(n==2)
		return 2;
	while(n>2)
	{
		a=a+b;
		n--;
		if(n==2)
			return a;
		b=a+b;
		n--;
	}
	return b;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	long long n=0;
	while(scanf("%ld",&n)!=EOF)
	{
		printf("%ld\n",f(n));
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