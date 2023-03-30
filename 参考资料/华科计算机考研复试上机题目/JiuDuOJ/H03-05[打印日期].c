#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目1186：打印日期
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4634解决：1633
题目描述：
给出年分m和一年中的第n天，算出第n天是几月几号。
输入：
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出：
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
样例输入：
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
样例输出：
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01

*/


//判定年份year是否是闰年
Boolean isLeapYear(int year)
{
	if( (year%100!=0&&year%4==0) || year%400==0)
		return TRUE;
	return FALSE;
}

Status covert(int year,int days)
{
	int monthDay[2][12]={  {31,28,31,30,31,30,31,31,30,31,30,31},
						{31,29,31,30,31,30,31,31,30,31,30,31}};
	int N=isLeapYear(year);
	int month=1,day=0;

	while(days>0)
	{
		if(days-monthDay[N][month-1]>0)
		{
			days-=monthDay[N][month-1];
			month++;
		}
		else
		{
			day=days;
			break;
		}
	}

	printf("%04d-%02d-%02d\n",year,month,day);
	return OK;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int year=0;
	int days=0;
	while(scanf("%d %d",&year,&days) != EOF)
	{
		covert(year,days);
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