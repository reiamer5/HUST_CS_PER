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
题目1132：与7无关的数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1444解决：929
题目描述：
一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7,
则称其为与7相关的数.现求所有小于等于n(n<100)的与7无关的正整数的平方和。
输入：
案例可能有多组。对于每个测试案例输入为一行,正整数n,(n<100)
输出：
对于每个测试案例输出一行，输出小于等于n的与7无关的正整数的平方和。
样例输入：
21
样例输出：
2336
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7855-1-1.html
*/
//n是与7相关的数 返回TRUE 否则返回FALSE
Boolean judge(int n)
{
	if(n%7==0)
		return TRUE;
	while(n>0)
	{
		if(n%10==7)
		{
			return TRUE;
		}
		n=n/10;
	}
	return FALSE;
}
int handleFunction(int n)
{
	int i=1;
	int sum=0;
	while(i<=n)
	{
		if(judge(i)==FALSE)
		{
			sum=sum+i*i;
		}
		i++;
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