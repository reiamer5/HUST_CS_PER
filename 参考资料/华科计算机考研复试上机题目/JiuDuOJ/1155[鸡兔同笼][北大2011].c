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
题目1155：鸡兔同笼
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1804解决：1214
题目描述：
一个笼子里面关了鸡和兔子（鸡有2只脚，兔子有4只脚，没有例外）。已经知道了笼子里面脚的总数a，
问笼子里面至少有多少只动物，至多有多少只动物。
输入：
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，每行一个正整数a (a < 32768)
输出：
输出包含n行，每行对应一个输入,包含两个正整数，第一个是最少的动物数，第二个是最多的动物数，两个正整数用一个空格分开
如果没有满足要求的答案，则输出两个0。
样例输入：
2
3
20
样例输出：
0 0
5 10
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7878-1-1.html

*/
Status handleFunction(int total)
{
	int sum1=0,sum2=0;
	int i=0,j=0;

	if(total&&total%2==0)
	{
		if(total%4)
		{
			sum1=total/4+1;
			sum2=total/2;
		}
		else
		{
			sum1=total/4;
			sum2=total/2;
		}
	}
	printf("%d %d\n",sum1,sum2);

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,total=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&total);
		handleFunction(total);		
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