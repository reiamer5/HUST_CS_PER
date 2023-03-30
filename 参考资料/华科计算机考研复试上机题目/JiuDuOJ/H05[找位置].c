#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define N 1000

typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目1199：找位置
时间限制：1 秒内存限制：32 兆特殊判题：否 提交：1752解决：863
题目描述：
对给定的一个字符串，找出有重复的字符，并给出其位置，如：abcaaAB12ab12
输出：a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13。
输入：
输入包括一个由字母和数字组成的字符串，其长度不超过100。
输出：
可能有多组测试数据，对于每组数据，
按照样例输出的格式将字符出现的位置标出。
样例输入：
abcaaAB12ab12
样例输出：
a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12
提示：
1、下标从0开始。
2、相同的字母在一行表示出其出现过的位置。

*/


Status search(char str[N],int n)
{
	int i=0,j=0;
	Boolean mark=TRUE;//每种字母第一次的输出控制
	for(i=0;i<n;i++)//for #1
	{
		mark=TRUE;
		//mark=FLASE;
		if(str[i]=='\0')
			continue;
		for(j=i+1;j<n;j++)//end:for #2
		{	
			if(str[j]=='\0')
				continue;
			if(str[i]==str[j])
			{
				if(mark==TRUE)
				{
					printf("%c:%d",str[i],i);
					mark=FALSE;
				}
				printf(",%c:%d",str[j],j);
				str[j]='\0';//避免再次被搜到
			}		
		}//end:for #2
		if(FALSE==mark)
			printf("\n");
	}//end:for #1
	return OK;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	char str[N];
	int n=0;

	while(gets(str) != NULL)
	{
		search(str,strlen(str));
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