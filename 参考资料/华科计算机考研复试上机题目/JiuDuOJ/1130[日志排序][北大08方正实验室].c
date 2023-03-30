#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define M 80
#define N 10100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1130：日志排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1176解决：273
题目描述：
有一个网络日志，记录了网络中计算任务的执行情况，每个计算任务对应一条如下形式的日志记录：
"hs_10000_p"是计算任务的名称，
"2007-01-17 19:22:53,315"是计算任务开始执行的时间"年-月-日 时：分：秒，毫秒"， 
"253.035(s)"是计算任务消耗的时间(以秒计)
hs_10000_p 2007-01-17 19:22:53,315 253.035(s)
请你写一个程序，对日志中记录计算任务进行排序。
时间消耗少的计算任务排在前面，时间消耗多的计算任务排在后面。
如果两个计算任务消耗的时间相同，则将开始执行时间早的计算任务排在前面。
输入：
日志中每个记录是一个字符串，每个字符串占一行。最后一行为空行，表示日志结束。日志中最多可能有10000条记录。
计算任务名称的长度不超过10，开始执行时间的格式是YYYY-MM-DD HH:MM:SS,MMM，消耗时间小数点后有三位数字。
计算任务名称与任务开始时间、消耗时间之间以一个或多个空格隔开，行首和行尾可能有多余的空格。
输出：
排序好的日志记录。每个记录的字符串各占一行。
输入的格式与输入保持一致，输入包括几个空格，你的输出中也应该包含同样多的空格。
样例输入：
hs_10000_p   2007-01-17 19:22:53,315     253.035(s)
hs_10001_p   2007-01-17 19:22:53,315     253.846(s)
hs_10002_m   2007-01-17 19:22:53,315     129.574(s)
hs_10002_p   2007-01-17 19:22:53,315     262.531(s)
hs_10003_m   2007-01-17 19:22:53,318     126.622(s)
hs_10003_p   2007-01-17 19:22:53,318     136.962(s)
hs_10005_m   2007-01-17 19:22:53,318     130.487(s)
hs_10005_p   2007-01-17 19:22:53,318     253.035(s)
hs_10006_m   2007-01-17 19:22:53,318     248.548(s)
hs_10007_p   2007-01-13 19:25:23,367    3146.827(s)
hs_10008_m   2007-01-17 19:22:53,318     248.548(s)
hs_10009_p   2004-01-17 19:25:23,367    3146.827(s)
样例输出：
hs_10003_m   2007-01-17 19:22:53,318     126.622(s)
hs_10002_m   2007-01-17 19:22:53,315     129.574(s)
hs_10005_m   2007-01-17 19:22:53,318     130.487(s)
hs_10003_p   2007-01-17 19:22:53,318     136.962(s)
hs_10006_m   2007-01-17 19:22:53,318     248.548(s)
hs_10000_p   2007-01-17 19:22:53,315     253.035(s)
hs_10005_p   2007-01-17 19:22:53,318     253.035(s)
hs_10001_p   2007-01-17 19:22:53,315     253.846(s)
hs_10002_p   2007-01-17 19:22:53,315     262.531(s)
hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7853-1-1.html
*/


typedef struct TaskNode
{
	char name[11];
	char date[11];
	char time[20];
	char costT[25];
}TaskNode;

 
char str[N][M];
int comp(const void *p1,const void *p2)
{
	char *str1=(char *)p1;
	char *str2=(char *)p2;
	TaskNode tp1,tp2;
	double diff1;	
	int diff2=0;
	sscanf(str1,"%s%s%s%s",&(tp1.name),&(tp1.date),&(tp1.time),&(tp1.costT));
	sscanf(str2,"%s%s%s%s",&(tp2.name),&(tp2.date),&(tp2.time),&(tp2.costT));
	diff1=atof(tp1.costT)-atof(tp2.costT);

	if(diff1==0.0)
	{
		diff2=strcmp(tp1.date,tp2.date);
		if(diff2==0)
		{
			return 	strcmp(tp1.time,tp2.time);
		}
		else
		{
			return diff2;
		}
	}
	else
	{
		return diff1>0?1:-1;
	}
}
 
Status handleFunction(int size)
{
	int i=0;
	qsort(str,size,sizeof(str[0]),comp);

	for(i=0;i<size;i++)
	{
		printf("%s\n",str[i]);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;

	while(gets(str[i]))//while 1#
	{
		i++;
	}//end:while 1#
	handleFunction(i);
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