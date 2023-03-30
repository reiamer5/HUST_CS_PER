#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 256
typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
    输入一个ip地址串，判断是否合法。
输入：
    输入的第一行包括一个整数n(1<=n<=500)，代表下面会出现的IP地址的个数。
    接下来的n行每行有一个IP地址，IP地址的形式为a.b.c.d，其中a、b、c、d都是整数。
输出：
    可能有多组测试数据，对于每组数据，如果IP地址合法则输出"Yes!"，否则输出"No!"。
样例输入：
2
255.255.255.255
512.12.2.3
样例输出：
Yes!
No!
提示：
合法的IP地址为：
a、b、c、d都是0-255的整数。


*/

Boolean check(char ip[N])
{
	int n=strlen(ip);
	int i=0;
	int sum=0;
	while(ip[i]!='\0')
	{
		if(ip[i]=='.')
		{
			if(sum>255||sum<0)
			{
				return FALSE;
			}
			sum=0;
			
		}
		else if(ip[i]>='0'&&ip[i]<='9')
		{
			sum=10*sum+ip[i]-'0';
		}
		else
		{
			return FALSE;
		}
		i++;
	}

	if(sum>255||sum<0)
	{
		return FALSE;
	}
	return TRUE;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char ip[N];
	int n=0;
	while(scanf("%d",&n)!=EOF)
	{
		while((n--)>0)
		{	
			scanf("%s",ip);
			if(check(ip)==TRUE)
			{
				printf("Yes!\n");
			}
			else
			{
				printf("No!\n");
			}
			ip[0]='\0';
		}	
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