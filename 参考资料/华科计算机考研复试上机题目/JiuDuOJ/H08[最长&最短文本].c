#include<stdio.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define M 1000
#define N 1000
/*

题目描述：
    输入多行字符串，请按照原文本中的顺序输出其中最短和最长的字符串，如果最短和最长的字符串不止一个，请全部输出。
输入：
输入包括多行字符串，字符串的长度len,(1<=len<=1000)。
输出：
按照原文本中的顺序输出其中最短和最长的字符串，如果最短和最长的字符串不止一个，请全部输出。
样例输入：
hello
she
sorry
he
样例输出：
he
hello
sorry
*/

//char strs[M][N];

char maxStr[M][N];
int maxStrLen=0;
int maxNum=-1;

char minStr[M][N];
int minStrLen=10000;
int minNum=0;

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int n=0;
	char s[N];
	int i=0;
	while(gets(s)!=NULL)
	{
		n=strlen(s);
		if(n>maxStrLen)
		{
			maxNum=0;
			strcpy(maxStr[maxNum],s);
			maxStrLen=n;
			maxNum++;
		}
		else if(n==maxStrLen)
		{
			strcpy(maxStr[maxNum],s);
			maxNum++;
		}

		if(n<minStrLen)
		{
			minNum=0;
			strcpy(minStr[minNum],s);
			minStrLen=n;
			minNum++;
		}
		else if(n==minStrLen)
		{
			strcpy(minStr[minNum],s);
			minNum++;
		}
		
	}
	for(i=0;i<minNum;i++)
	{
		printf("%s\n",minStr[i]);
	}

	for(i=0;i<maxNum;i++)
	{
		printf("%s\n",maxStr[i]);
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