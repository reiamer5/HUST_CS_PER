#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//#define M 256
#define N 2048
//#define MININT -32768
typedef char ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。
输入：
输入包括一行字符串，其长度不超过1000。
输出：
可能有多组测试数据，对于每组数据，如果是回文字符串则输出"Yes!"，否则输出"No!"。
样例输入：
hellolleh
helloworld
样例输出：
Yes!
No!

*/


Boolean check(ElemType str[N])
{

	int high=strlen(str)-1;
	int low=0;
	while(low<high)
	{
		if(str[low]!=str[high])
		{
			return FALSE;
		}
		low++;
		high--;
	}
	return TRUE;
}



//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	ElemType str[N];

	while(scanf("%s",str)!=EOF)
	{

		if(TRUE==check(str))
			printf("Yes!\n");
		else
			printf("No!\n");
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