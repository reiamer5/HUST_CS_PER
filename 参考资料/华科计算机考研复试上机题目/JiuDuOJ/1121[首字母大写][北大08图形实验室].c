#include<stdio.h>
#include<ctype.h>
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
题目1121：首字母大写
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2570解决：887
题目描述：
对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。
在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
输入：
输入一行：待处理的字符串（长度小于100）。
输出：
可能有多组测试数据，对于每组数据，
输出一行：转换后的字符串。
样例输入：
if so, you already have a google account. you can sign in on the right.
样例输出：
If So, You Already Have A Google Account. You Can Sign In On The Right.
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7844-1-1.html
*/
Status handleFunction(char str[N])
{
	Boolean flag=TRUE;
	int i=0;
	while(str[i]!='\0')
	{
		if(flag==TRUE)
		{
			str[i]=toupper(str[i]);
		}
		if(str[i]==' '||str[i]=='\t'||str[i]=='\r'||str[i]=='\n'||str[i]=='.'||str[i]==',')
		{
			flag=TRUE;
		}
		else
		{
			flag=FALSE;
		}
		i++;
	}

	printf("%s\n",str);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];

	while(gets(str)!=NULL)//while 1#
	{
		handleFunction(str);
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