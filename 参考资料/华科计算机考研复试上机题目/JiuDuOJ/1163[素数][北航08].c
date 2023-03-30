#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

typedef int ElemType;

//#define M 1000
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1163：素数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：6679解决：2273
题目描述：
输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
输入：
输入有多组数据。
每组一行，输入n。
输出：
输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数(素数之间用空格隔开，最后一个素数后面没有空格)，如果没有则输出-1。
样例输入：
100
样例输出：
11 31 41 61 71
来源：
2008年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7886-1-1.html
*/

int data[N];
int count=0;
//如果n是素数返回TRUE否则返回FALSE
Boolean prime(int n)
{
	int i=2;
	int limit=(int)sqrt(n);
	if(n==1||n==2)
		return FALSE;

	for(i=2;i<=limit;i++)
	{
		if(n%i==0)
			return FALSE;
	}
	return TRUE;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		count=0;
		for(i=0;i<n;i++)
		{
			if(i>2&&TRUE==prime(i)&&i%10==1)
				data[count++]=i;			
		}
		if(count==0)
		{
			printf("-1\n");
		}
		else
		{
			for(i=0;i<count-1;i++)
			{
				printf("%d ",data[i]);
			}
			printf("%d\n",data[i]);
		}
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