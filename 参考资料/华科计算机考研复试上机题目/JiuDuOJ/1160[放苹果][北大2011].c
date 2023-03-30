#include<stdio.h>
//定义状态码
#define OK 1
#define ERROR 0
typedef int Status;
/*************************题目说明********************/
/*
题目1160：放苹果
时间限制：1 秒内存限制：32 兆特殊判题：否提交：842解决：571
题目描述：
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入：
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出：
对输入的每组数据M和N，用一行输出相应的K。
样例输入：
1
7 3
样例输出：
8
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7883-1-1.html
*/
int divide(int m,int n)
{
	if(m==0||m==1||n==1)
		return 1;
	if(m<0)
		return 0;		
	return divide(m-n,n)+divide(m,n-1);

}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int m=0,n=0,k=0,i=0;
	
	scanf("%d",&k);

	for(i=0;i<k;i++)
	{
		scanf("%d %d",&m,&n);
		printf("%d\n",divide(m,n));		
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