#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 1024
#define NUM 256
typedef int Status;
typedef int Boolean;

/*
编一个程序，读入用户输入的，以“.”结尾的一行文字，统计一共有多少个单词，并分别输出每个单词含有多少个字符。
（凡是以一个或多个空格隔开的部分就为一个单词）
输入：
输入包括1行字符串，以“.”结束，字符串中包含多个单词，单词之间以一个或多个空格隔开。
输出：
可能有多组测试数据，对于每组数据，
输出字符串中每个单词包含的字母的个数。
样例输入：
hello how are you.
样例输出：
5 3 3 3
*/

/*
str 待处理的字符串
counts 存放统计的结果
num 单词的数量
*/
Status count(char str[N],int counts[NUM],int *num)
{
	int i=0;//遍历单词的下标
	int j=0;//单词的个数
	int k=0;//每个单词的字母数
	while(str[i]!='.'&&str[i]!='\0')//while #1
	{
		if(str[i]==' ')//一个单词结束
		{
			counts[j]=k;
			j++;
			k=0;//单词字母数计数器清零
			while(str[i]==' ')//while #2 跳过一个单词结束后所有的空格
			{
				i++;
			}//end:while #2 
		}
		else
		{
			i++;
			k++;//单词的字母数加一
		}			
	}//end:while #1

	if(i>0&&str[i-1]!=' ')
	{
		counts[j]=k;//处理最后一个单词
		j++;
	}

	*num=j;//单词的个数
	return OK;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int num=0;
	char str[N];
	int counts[NUM];
	int i=0;

	while( gets(str) != EOF)
	{
	
		count(str,counts,&num);

		for(i=0;i<num-1;i++)
		{
			printf("%d ",counts[i]);
		}	
		//避免最后一个输出空格
		if(num>0)
			printf("%d\n",counts[i]);
		str[0]='\0';
		num=0;
		
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