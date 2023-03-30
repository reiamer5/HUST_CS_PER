#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
/*

题目描述：
输入一个整数，将其转换成八进制数输出。
输入：
输入包括一个整数N(0<=N<=100000)。
输出：
可能有多组测试数据，对于每组数据，
输出N的八进制表示数。
样例输入：
7
8
9
样例输出：
7
10
11

*/


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int n=0;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%o\n",n);
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