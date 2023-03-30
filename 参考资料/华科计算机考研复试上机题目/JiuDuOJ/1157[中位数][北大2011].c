#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//#define M 1000
#define N 10100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1157：中位数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1908解决：1149
题目描述：
中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数（或最中间两个数据的平均数）.
给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）
输入：
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1<=N<=10000.
接着N行为N个数据的输入，N=0时结束输入
输出：
输出中位数，每一组测试数据输出一行
样例输入：
4
10
30
20
40
3
40
30
50
4
1
2
3
4
0
样例输出：
25
40
2
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7880-1-1.html

*/

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
Status middle(int data[N],int num)
{
	qsort(data,num,sizeof(int),cmp);
	if(num%2)
	{
		printf("%d\n",data[(int)num/2]);
	}
	else
	{
		printf("%d\n",(data[(int)num/2]+data[((int)num/2)-1])/2 );
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	int data[N];
	while(scanf("%d",&n),n)//while 1#
	{
		memset(data,0,N);
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		middle(data,n);
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