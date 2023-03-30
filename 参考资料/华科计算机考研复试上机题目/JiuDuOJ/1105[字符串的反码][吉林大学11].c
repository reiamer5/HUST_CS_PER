#include<stdio.h>
#include<ctype.h>
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
#define N 100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1105：字符串的反码
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4443解决：1363
题目描述：
    一个二进制数，将其每一位取反，称之为这个数的反码。下面我们定义一个字符的反码。如果这是一个小写字符，则它和字符'a’的距离与
	它的反码和字符'z’的距离相同；如果是一个大写字符，则它和字符'A’的距离与它的反码和字符'Z’的距离相同；如果不是上面两种情况，
	它的反码就是它自身。
    举几个例子，'a’的反码是'z’；'c’的反码是'x’；'W’的反码是'D’；'1’的反码还是'1’；'$'的反码还是'$'。
    一个字符串的反码定义为其所有字符的反码。我们的任务就是计算出给定字符串的反码。
输入：
    输入每行都是一个字符串，字符串长度不超过 80 个字符。如果输入只有!，表示输入结束，不需要处理。
输出：
对于输入的每个字符串，输出其反码，每个数据占一行。
样例输入：
Hello 
JLU-CCST-2011 
!
样例输出：
Svool 
QOF-XXHG-2011
来源：
2011年吉林大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7828-1-1.html
*/
Status handleFunction(char *str)
{
	while(*str!='\0')
	{
		if(islower(*str))
		{
			*str='z'-(*str-'a');
		}
		else if(isupper(*str))
		{
			*str='Z'-(*str-'A');
		}
		str++;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	gets(str);
	while(strcmp("!",str))//while 1#
	{
		handleFunction(str);
		printf("%s\n",str);
		gets(str);
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