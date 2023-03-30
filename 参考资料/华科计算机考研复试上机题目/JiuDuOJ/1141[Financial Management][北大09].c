#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

typedef int Status;
typedef int Boolean;


//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1141：Financial Management
时间限制：1 秒内存限制：32 兆特殊判题：否提交：870解决：456
题目描述：
    Larry graduated this year and finally has a job. He's making a lot of money, but somehow never seems to have enough. 
	Larry has decided that he needs to grab hold of his financial portfolio and solve his financing problems. The first step is 
	to figure out what's been going on with his money. Larry has his bank account statements and wants to see how much money he has. 
	Help Larry by writing a program to take his closing balance from each of the past twelve months and calculate his average account 
	balance.
输入：
     Each case will be twelve lines. Each line will contain the closing balance of his bank account for a particular month. 
	 Each number will be positive and displayed to the penny. No dollar sign will be included.
输出：
    For each case, the output will be a single number, the average (mean) of the closing balances for the twelve months.
	It will be rounded to the nearest penny, preceded immediately by a dollar sign, and followed by the end-of-line. 
	There will be no other spaces or characters in the output. 
样例输入：
100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75
样例输出：
$1581.42
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7864-1-1.html

*/

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	double sum=0.0;
	double salary=0.0;
	int i=0;
	while(scanf("%lf",&salary)!=EOF)//while 1#
	{
		sum+=salary;
		for(i=0;i<11;i++)
		{
			scanf("%lf",&salary);
			sum+=salary;
		}
		printf("$%.2lf\n",sum/12);
		sum=0.0;
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