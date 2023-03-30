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
题目1059：abc
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3057解决：2418
题目描述：
设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。
输入：
题目没有任何输入。
输出：
请输出所有满足题目条件的a、b、c的值。
a、b、c之间用空格隔开。
每个输出占一行。
样例输入：
样例输出：
来源：
2000年清华大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7783-1-1.html

*/
Status handleFunction()
{
	int a,b,c;
	for(a=3;a<=4;a++)
	{
		for(b=1;b<=2;b++)
		{
			for(c=1;c<=6;c+=5)
			{
				if(a*100+b*110+c*12==532)
				{
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
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