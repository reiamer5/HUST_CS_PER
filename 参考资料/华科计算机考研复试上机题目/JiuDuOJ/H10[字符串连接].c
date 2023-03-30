#include<stdio.h>
//#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 1000
/*
题目1206：字符串连接
时间限制：1 秒内存限制：128 兆特殊判题：否提交：3582解决：1693
题目描述：
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输入：
每一行包括两个字符串，长度不超过100。
输出：
可能有多组测试数据，对于每组数据，
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输出连接后的字符串。
样例输入：
abc def
样例输出：
abcdef
*/
int strUnion(char stra[N],char strb[N])
{
	int i=0,j=0;
	while(stra[i]!='\0')
	{
		i++;
	}
	while(strb[j]!='\0')
	{
		stra[i]=strb[j];
		i++;
		j++;
	}

	stra[i]='\0';
	return i;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	char stra[N],strb[N];
	//int len=0;
	while(scanf("%s %s",stra,strb)!=EOF)
	{
		strUnion(stra,strb);
		printf("%s\n",stra);		
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