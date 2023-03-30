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
题目1106：数字之和
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2250解决：1528
题目描述：
对于给定的正整数 n，计算其十进制形式下所有位置数字之和，并计算其平方的各位数字之和。
输入：
每行输入数据包括一个正整数n(0<n<40000)，如果n=0 表示输入结束，并不用计算。
输出：
对于每个输入数据，计算其各位数字之和，以及其平方值的数字之和，输出在一行中，之间用一个空格分隔，但行末不要有空格。
样例输入：
4
12
97
39999
0
样例输出：
4 7
3 9
16 22
39 36
来源：
2011年吉林大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7829-1-1.html

*/
int sumE(long n)
{
	int sum=0;
	while(n>0)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;

	while(scanf("%d",&n),n)//while 1#
	{
		printf("%d %d\n",sumE(n),sumE(n*n));
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