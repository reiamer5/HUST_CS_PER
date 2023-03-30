#include<stdio.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 1000

/*************************题目说明********************/
/*

题目1471：合并符串
时间限制：1 秒内存限制：128 兆特殊判题：否提交：1195解决：525
题目描述：
给定两个字符串S1和S2，合并成一个新的字符串S。
合并规则为，S1的第一个字符为S的第一个字符，将S2的最后一个字符作为S的第二个字符；
将S1的第二个字符作为S的第三个字符，将S2的倒数第二个字符作为S的第四个字符，以此类推。
输入：
包含多组测试数据，每组测试数据包含两行，代表长度相等的两个字符串S1和S2（仅由小写字母组成，长度不超过100）。
输出：
合并后的新字符串S
样例输入：
abc
def
样例输出：
afbecd
来源：
2011年西北工业大学计算机研究生机试真题

*/
Status specialStract(char str1[N],char str2[N],char str3[N])
{
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i=0,j=len2-1,k=0;

	while(str1[i]!='\0'&&j>=0)
	{
		str3[k++]=str1[i++];
		str3[k++]=str2[j--];
	}

	while(str2[i]!='\0')
	{
		str3[k++]=str1[i++];
	}

	while(j>=0)
	{
		str3[k++]=str2[j--];
	}
	str3[k]='\0';
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	char str1[N],str2[N],str3[N];
	while(scanf("%s %s",str1,str2)!=EOF)//while 1#
	{
		specialStract(str1,str2,str3);
		printf("%s\n",str3);
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