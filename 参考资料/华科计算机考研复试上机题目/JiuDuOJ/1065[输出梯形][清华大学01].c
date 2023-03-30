#include<stdio.h>

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
题目1065：输出梯形
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4359解决：2377
题目描述：
输入一个高度h，输出一个高为h，上底边为h的梯形。
输入：
一个整数h(1<=h<=1000)。
输出：
h所对应的梯形。
样例输入：
4
样例输出：
      ****
    ******
  ********
**********
提示：
梯形每行都是右对齐的，sample中是界面显示问题
来源：
2001年清华大学计算机研究生机试真题(第II套)
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7789-1-1.html
*/
Status handleFunction(int n)
{
	int space=2*n-2;//(n-1)*2
	int limit=3*n-2;
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<limit;j++)
		{
			if(j<space)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
		space-=2;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	while(scanf("%d",&n)!=EOF)
		handleFunction(n);
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