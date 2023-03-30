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
题目1064：反序数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3123解决：2331
题目描述：
设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）
求N的值
输入：
程序无任何输入数据
输出：
输出题目要求的四位数，如果结果有多组，则每组结果之间以回车隔开
样例输入：
样例输出：
来源：
2001年清华大学计算机研究生机试真题(第I套)
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7788-1-1.html

*/
Status handleFunction()
{
	int i=1111;
	for(i=1000;i<=9999;i++)
	{
		if((i%10*1000+i%100/10*100+i%1000/100*10+i/1000)==i*9)
		{
			printf("%d\n",i);
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