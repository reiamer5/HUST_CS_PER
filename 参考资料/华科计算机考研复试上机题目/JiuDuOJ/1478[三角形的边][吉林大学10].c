#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目描述：
给定三个已知长度的边，确定是否能够构成一个三角形，这是一个简单的几何问题。我们都知道，这要求两边之和大于第三边。实际上，并不需要检验所有三种可能，只需要计算最短的两个边长之和是否大于最大那个就可以了。
这次的问题就是：给出三个正整数，计算最小的数加上次小的数与最大的数之差。
输入：
每一行包括三个数据a, b, c，并且都是正整数，均小于10000。当a为0时标志所有输入数据结束。
输出：
对于输入的每一行，在单独一行内输出结果s。s=min(a,b,c)+mid(a,b,c)-max(a,b,c)。上式中，min为最小值，mid为中间值，max为最大值。
样例输入：
1 2 3
6 5 4
10 20 15
1 1 100
0 0 0
样例输出：
0
3
5
-98

*/
int min(int a,int b,int c)
{
	if(a<=b&&a<=c)
	{
		return a;
	}
	else if(b<=a&&b<=c)
	{
		return b;
	}
	return c;
}

int max(int a,int b,int c)
{
	if(a>=b&&a>=c)
	{
		return a;
	}
	else if(b>=a&&b>=c)
	{
		return b;
	}
	return c;
}
int mid(int a,int b,int c)
{
	if((b<=a&&a<=c)||(c<=a&&a<=b))
	{
		return a;
	}
	else if((a<=b&&b<=c)||(c<=b&&b<=a))
	{
		return b;
	}
	return c;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int a=0,b=0,c=0;
	scanf("%d %d %d",&a,&b,&c);
	while(a)//while 1#
	{
		printf("%d\n",min(a,b,c)+mid(a,b,c)-max(a,b,c));
		scanf("%d %d %d",&a,&b,&c);
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