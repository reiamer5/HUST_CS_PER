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
题目1122：吃糖果
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1205解决：961
题目描述：
名名的妈妈从外地出差回来，带了一盒好吃又精美的巧克力给名名（盒内共有 N 块巧克力，20 > N >0）。
妈妈告诉名名每天可以吃一块或者两块巧克力。
假设名名每天都吃巧克力，问名名共有多少种不同的吃完巧克力的方案。
例如：
如果N=1，则名名第1天就吃掉它，共有1种方案；
如果N=2，则名名可以第1天吃1块，第2天吃1块，也可以第1天吃2块，共有2种方案；
如果N=3，则名名第1天可以吃1块，剩2块，也可以第1天吃2块剩1块，所以名名共有2+1=3种方案；
如果N=4，则名名可以第1天吃1块，剩3块，也可以第1天吃2块，剩2块，共有3+2=5种方案。
现在给定N，请你写程序求出名名吃巧克力的方案数目。
输入：
输入只有1行，即整数N。
输出：
可能有多组测试数据，对于每组数据，
输出只有1行，即名名吃巧克力的方案数。
样例输入：
4
样例输出：
5
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7845-1-1.html
*/
int f(int n)
{
	int  k=n;
	int  a=1,b=2;

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

	int n=0;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",f(n));
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