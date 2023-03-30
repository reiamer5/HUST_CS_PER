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
题目1062：分段函数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2984解决：1752
题目描述：
编写程序，计算下列分段函数y=f(x)的值。
y=-x+2.5; 0<=x<2
y=2-1.5(x-3)(x-3); 2<=x<4
y=x/2-1.5; 4<=x<6
输入：
一个浮点数N
输出：
测试数据可能有多组，对于每一组数据，
输出N对应的分段函数值：f(N)。结果保留三位小数
样例输入：
1
样例输出：
1.500
来源：
2001年清华大学计算机研究生机试真题(第I套)
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7786-1-1.html

*/
double handleFunction(double x)
{
	if(0<=x&&x<2)
	{
		return -x+2.5;
	}
	else if(2<=x&&x<4)
	{
		return 2-1.5*(x-3)*(x-3);
	}
	else
	{
		return x/2-1.5;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	double x=0.0;
	while(scanf("%lf",&x)!=EOF)//while 1#
	{
		printf("%.3lf\n",handleFunction(x));
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