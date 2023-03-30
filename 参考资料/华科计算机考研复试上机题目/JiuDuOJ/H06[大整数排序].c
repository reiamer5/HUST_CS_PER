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
#define N 256
#define LENGTH 1024
typedef int ElemType;
typedef int Status;
typedef int Boolean;

/*
题目描述：
对N个长度最长可达到1000的数进行排序。
输入：
输入第一行为一个整数N，(1<=N<=100)。
接下来的N行每行有一个数，数的长度范围为1<=len<=1000。
每个数都是一个正数，并且保证不包含前缀零。
输出：
可能有多组测试数据，对于每组数据，将给出的N个数从小到大进行排序，输出排序后的结果，每个数占一行。
样例输入：
3
11111111111111111111111111111
2222222222222222222222222222222222
33333333
样例输出：
33333333
11111111111111111111111111111
2222222222222222222222222222222222

*/

int comp(const void *stra,const void *strb)
{
	char *str1=(char*)stra;
	char *str2=(char*)strb;

	int len1=strlen((char*)str1);
	int len2=strlen((char*)str2);
	if(len1==len2)
		return strcmp(str1,str2);
	return len1-len2;
}

Status bSort(char str[N][LENGTH],int n)
{
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N][LENGTH];
	int n=0;
	int i=0;
	while(scanf("%d",&n)!=EOF)
	{

		for(i=0;i<n;i++)
		{
			scanf("%s",str+i);
		}

		qsort(str,n,sizeof(str[0]),comp);
		
		for(i=0;i<n;i++)
		{
			printf("%s\n",*(str+i));
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