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
题目1142：Biorhythms
时间限制：1 秒内存限制：32 兆特殊判题：否提交：237解决：164
题目描述：
    Some people believe that there are three cycles in a person's life that start the day he or she is born. 
	These three cycles are the physical, emotional, and intellectual cycles, and they have periods of lengths 23, 28,
	and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle,
	a person performs at his or her best in the corresponding field (physical, emotional or mental). 
	For example, if it is the mental curve, thought processes will be sharper and concentration will be easier. 
Since the three cycles have different periods, the peaks of the three cycles generally occur at different times.
 We would like to determine when a triple peak occurs (the peaks of all three cycles occur in the same day) for any person. 
 For each cycle, you will be given the number of days from the beginning of the current year at which one of its peaks 
 (not necessarily the first) occurs. You will also be given a date expressed as the number of days from the beginning 
 of the current year. You task is to determine the number of days from the given date to the next triple peak. 
 The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, 
 the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the 
 next occurrence of a triple peak.
输入：
    You will be given a number of cases. The input for each case consists of one line of four integers p, e, i, 
	and d. The values p, e, and i are the number of days from the beginning of the current year at which the physical, 
	emotional, and intellectual cycles peak, respectively. The value d is the given date and may be smaller than
	any of p, e, or i. All values are non-negative and at most 365, and you may assume that a triple peak will 
	occur within 21252 days of the given date. The end of input is indicated by a line in which p = e = i = d = -1. 
输出：
    For each test case, print the case number followed by a message indicating the number of days to the next triple peak, 
	in the form:
    Case 1: the next triple peak occurs in 1234 days.
    Use the plural form "days'' even if the answer is 1. 
样例输入：
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1
样例输出：
Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7865-1-1.html

*/
Status triplePeak (int p,int e,int i,int d)
{
	int count=0;
	int i1=0,i2=0,i3=0;

	while(p>0||e>0||i>0)
	{
		count++;
		p>0? p--:i1++;
		e>0? e--:i2++;
		i>0? i--:i3++;
	
	}

	if(p==0&&e==0&&i==0)
	{
		i1++;
		i2++;
		i3++;
		count++;
	}

	while(i1%23!=0||i2%28!=0||i3%33!=0)
	{
		i1++;
		i2++;
		i3++;
		count++;
	}
	return count-d;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int p,e,i,d;
	int seq=0;
	scanf("%d %d %d %d",&p,&e,&i,&d);
	
	while(!(p==-1&&e==-1&&i==-1&&d==-1))//while 1#
	{
		seq++;
		printf("Case %d: the next triple peak occurs in %d days.\n",seq,triplePeak(p,e,i,d));
		scanf("%d %d %d %d",&p,&e,&i,&d);
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