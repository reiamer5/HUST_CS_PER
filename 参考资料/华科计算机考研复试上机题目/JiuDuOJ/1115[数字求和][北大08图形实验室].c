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

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2089解决：1340
题目描述：
给定一个正整数a，以及另外的5个正整数，问题是：这5个整数中，小于a的整数的和是多少？
输入：
输入一行，只包括6个小于100的正整数，其中第一个正整数就是a。
输出：
可能有多组测试数据，对于每组数据，
输出一行，给出一个正整数，是5个数中小于a的数的和。
样例输入：
10 1 2 3 4 11
样例输出：
10
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7838-1-1.html
九度Online Judge修改自HUSTOJ | 浙ICP备09099636号 | 九度Online Judge版权所有
*/

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,k,sum=0;
	
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		scanf("%d",&k);	
		if(k<n)
			sum+=k;
	}
	printf("%d\n",sum);
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