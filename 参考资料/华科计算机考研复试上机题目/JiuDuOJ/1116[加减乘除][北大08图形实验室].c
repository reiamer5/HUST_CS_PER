#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
题目1116：加减乘除
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1284解决：797
题目描述：
根据输入的运算符对输入的整数进行简单的整数运算。
运算符只会是加+、减-、乘*、除/、求余%、阶乘！六个运算符之一。
输出运算的结果，如果出现除数为零，则输出"error",如果求余运算的第二个运算数为0，也输出"error"。
输入：
输入为一行。先输入第一个整数，空格输入运算符，然后再空格输入第二个整数，回车结束本次输入。
如果运算符为阶乘！符号，则不输入第二个整数，直接回车结束本次输入。
输出：
可能有多组测试数据，对于每组数据，
输出一行。输出对输入的两个（或一个）数，根据输入的运算符计算的结果，或者"error"。
样例输入：
12 + 34
54 - 25
3 * 6
45 / 0
5 !
34 % 0
样例输出：
46
29
18
error
120
error
提示：
运算不会超出整型数据的范围。0!=1; 测试数据有多组。
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7839-1-1.html
*/

int nMti(int n)
{
	int sum=1;
	while(n>0)
	{
		sum*=n;
		n--;
	}
	return sum;
}
Status calculate(char str[N])
{
	char paStr[N];
	char pbStr[N];
	int pa=0;
	int pb=0;
	char *operat;
	if((operat=strchr(str,'+'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		strcpy(pbStr,operat+1);
		pa=atoi(paStr);
		pb=atoi(pbStr);
		printf("%d\n",pa+pb);
	}
	else if((operat=strchr(str,'-'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		strcpy(pbStr,operat+1);
		pa=atoi(paStr);
		pb=atoi(pbStr);
		printf("%d\n",pa-pb);
	}
	else if((operat=strchr(str,'*'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		strcpy(pbStr,operat+1);
		pa=atoi(paStr);
		pb=atoi(pbStr);
		printf("%d\n",pa*pb);
	}
	else if((operat=strchr(str,'/'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		strcpy(pbStr,operat+1);
		pa=atoi(paStr);
		pb=atoi(pbStr);
		if(pb==0)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n",pa/pb);
		}
	}
	else if((operat=strchr(str,'%'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		strcpy(pbStr,operat+1);
		pa=atoi(paStr);
		pb=atoi(pbStr);
		if(pb==0)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n",pa%pb);
		}
	}
	else if((operat=strchr(str,'!'))!=NULL)
	{	
		strncpy(paStr,str,operat-str);
		pa=atoi(paStr);
		printf("%d\n",nMti(pa));
	
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];

	while(gets(str)!=NULL)//while 1#
	{
		calculate(str);
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