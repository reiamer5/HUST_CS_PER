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

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1476：平方因子
时间限制：1 秒内存限制：128 兆特殊判题：否提交：635解决：416
题目描述：
给定一个数n，判定它是否有一个不为1的完全平方数因子。也就是说，是否存在某个k，k>1，使得k*k能够整除n。
输入：
每行一个整数n，1<n<10000，n=0标志输入结束。
输出：
对于每一个输入的整数，在单独的一行输出结果，如果有不为1的完全平方数因子，则输出Yes，否则输出No。请注意大小写。
样例输入：
15
12
0
样例输出：
No
Yes
*/
Boolean judge(int n)
{
	int limit=(int)sqrt(n);
	int i=0;
	for(i=2;i<=limit;i++)
	{
		if(n%i==0&&n%(i*i)==0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	while(scanf("%d",&n),n)//while 1#
	{
		if(TRUE==judge(n))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
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