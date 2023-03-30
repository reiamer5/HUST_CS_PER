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

typedef char ElemType;

#define M 100
#define N 100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1168：字符串的查找删除
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3294解决：1294
题目描述：
给定一个短字符串（不含空格），再给定若干字符串，在这些字符串中删除所含有的短字符串。
输入：
输入只有1组数据。
输入一个短字符串（不含空格），再输入若干字符串直到文件结束为止。
输出：
删除输入的短字符串(不区分大小写)并去掉空格,输出。
样例输入：
in
#include 
int main()
{

printf(" Hi ");
}
样例输出：
#clude
tma()
{

prtf("Hi");
}
提示：
注:将字符串中的In、IN、iN、in删除。
来源：
2009年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7891-1-1.html
*/

//删除str字符串中所有值为c的字符
Status deleteChar(ElemType *str,char c)
{
	int i=0,k=0;
	while(str[k]!='\0')
	{
		if(str[k]!=c)
		{
			str[i]=str[k];
			i++;
		}
		k++;
	}
	str[i]='\0';
	return OK;
}

//删除str中的空格 以及 和sStr相等的字符串
Status deleteStr(ElemType str[N],ElemType sStr[N])
{
	int i=0,j=0,k=0;
	while(str[i]!='\0')
	{
	
		if(str[i]==sStr[k])
		{	
			j=i;
			while(str[i]==sStr[k]&&str[i]!='\0'&&sStr[k]!='\0')
			{
				i++;
				k++;
			}
			if(sStr[k]=='\0')
			{
				while(j<i)
				{
					str[j]=' ';
					j++;
				}
			}
			else
			{
				i=j+1;
			}	
			k=0;
		}
		else
		{
			i++;
		}
	}
	deleteChar(str,' ');
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[M][N],sStr[N];
	int i=0,j=0;
	while(scanf("%s",sStr)!=EOF)//while 1#
	{
		getchar();
		while(gets(str[i]))
		{
			deleteStr(str[i],sStr);	
			i++;
		}
		while(j<i)
		{
			printf("%s\n",str[j++]);
		}
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