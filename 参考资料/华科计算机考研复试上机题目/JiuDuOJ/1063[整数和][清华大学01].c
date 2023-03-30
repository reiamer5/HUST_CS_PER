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
题目1063：整数和
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3112解决：2025
题目描述：
编写程序，读入一个整数N。
若N为非负数，则计算N到2N之间的整数和；
若N为一个负数，则求2N到N之间的整数和
输入：
一个整数N,N的绝对值小于等于1000
输出：
测试数据可能有多组，对于每一组数据，
输出题目要求的值
样例输入：
1
-1
样例输出：
3
-3
来源：
2001年清华大学计算机研究生机试真题(第I套)
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7787-1-1.html

*/
Status handleFunction(int n)
{
	int sum=0;
	int k=2*n;
	int i=0;
	if(n<0)
	{
		for(i=k;i<=n;i++)
		{
			sum+=i;
		}
	}
	else
	{
		for(i=k;i>=n;i--)
		{
			sum+=i;
		}
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		printf("%d\n",handleFunction(n));
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