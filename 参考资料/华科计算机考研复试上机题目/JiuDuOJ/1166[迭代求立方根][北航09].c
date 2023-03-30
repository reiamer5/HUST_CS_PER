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
/*************************题目说明********************/
/*
题目1166：迭代求立方根
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3100解决：1416
题目描述：
立方根的逼近迭代方程是 y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n)),其中y0=x.求给定的x经过n次迭代后立方根的值。
输入：
输入有多组数据。
每组一行，输入x n。
输出：
迭代n次后的立方根，double精度,保留小数点后面六位。
样例输入：
3000000 28
样例输出：
144.224957
来源：
2009年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7889-1-1.html
*/

long double iteration(long double x,int n)
{
	long double y=x;
	long double t=1.0/3;
	if(x==0.0)
		return 0.0;
	while(n>0)
	{
		y=t*(2*y+x/(y*y));
		n--;
	}
	return y;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	long double x;
	while(scanf("%lf %d",&x,&n)!=EOF)//while 1#
	{
		printf("%.6lf\n",iteration(x,n));
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