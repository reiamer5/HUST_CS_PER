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
#define N 110

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1128：求平均年龄
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1919解决：996
题目描述：
班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。
输入：
第一行有一个整数n（1<= n <= 100），表示学生的人数。其后n行每行有1个整数，取值为15到25。
输出：
可能有多组测试数据，对于每组数据，
输出一行，该行包含一个浮点数，为要求的平均年龄，保留到小数点后两位。
样例输入：
2
18
17
样例输出：
17.50
提示：
要输出浮点数、双精度数小数点后2位数字，可以用下面这种形式： 
printf("%.2f", num);
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7851-1-1.html
*/
float avgAge(int ages[N],int nums)
{
	int i=0;
	float sum=0.0;
	while(i<nums)
	{
		sum+=ages[i++];
	}
	return (float)sum/nums;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	int ages[N];
	while (scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",ages+i);
		}

		printf("%.2f\n",avgAge(ages,n));
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