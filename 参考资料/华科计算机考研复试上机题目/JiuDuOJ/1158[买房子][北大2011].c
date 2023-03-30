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


//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1158：买房子
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1638解决：986
题目描述：
    某程序员开始工作，年薪N万，他希望在中关村公馆买一套60平米的房子，现在价格是200万，假设房子价格以每年百分之K增长，
	并且该程序员未来年薪不变，且不吃不喝，不用交税，每年所得N万全都积攒起来，问第几年能够买下这套房子（第一年房价200万，收入N万）
输入：
    有多行，每行两个整数N（10<=N<=50）, K（1<=K<=20）
输出：
    针对每组数据，如果在第20年或者之前就能买下这套房子，则输出一个整数M，表示最早需要在第M年能买下，否则输出Impossible，输出需要换行
样例输入：
50 10
40 10
40 8
样例输出：
8
Impossible
10
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7881-1-1.html

*/
Status handleFunction(int n,int k)
{
	double sum=n;
	double cost=200.0;
	double rate=k/100.0;
	int i=1;
	while(sum<cost&&i<=20)
	{
		sum+=n;
		cost+=cost*rate;
		//printf("%.2lf %.2lf\n",sum,cost);
		i++;
	}
	if(i<=20)
	{
		printf("%d\n",i);
	}
	else
	{
		printf("Impossible\n");
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0,k=0;
	while(scanf("%d %d",&n,&k)!=EOF)//while 1#
	{
		handleFunction(n,k);
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