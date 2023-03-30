#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//#define M 1000
#define N 10

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1058：反序输出
时间限制：1 秒内存限制：32 兆特殊判题：否提交：7764解决：2760
题目描述：
输入任意4个字符(如：abcd)， 并按反序输出(如：dcba)
输入：
题目可能包含多组用例，每组用例占一行，包含4个任意的字符。
输出：
对于每组输入,请输出一行反序后的字符串。
具体可见样例。
样例输入：
Upin
cvYj
WJpw
cXOA
样例输出：
nipU
jYvc
wpJW
AOXc
来源：
2000年清华大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7782-1-1.html
*/
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	int i=0;
	while(scanf("%s",str)!=EOF)//while 1#
	{
		for(i=3;i>=0;i--)
		{
			printf("%c",str[i]);
		}
		printf("\n");
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