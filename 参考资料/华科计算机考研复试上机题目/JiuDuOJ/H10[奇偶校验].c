#include<stdio.h>
//#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 9
#define M 1000
/*
题目1197：奇偶校验
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3037解决：1285
题目描述：
输入一个字符串，然后对每个字符进行奇校验，最后输出校验后的二进制数(如'3'，输出：10110011)。
输入：
输入包括一个字符串，字符串长度不超过100。
输出：
可能有多组测试数据，对于每组数据，
对于字符串中的每一个字符，输出按题目进行奇偶校验后的数，每个字符校验的结果占一行。
样例输入：
3
3a
样例输出：
10110011
10110011
01100001
*/

//校验一个字符c将结果存放在vStr中 奇校验
Status verifyCharO(char c,char vStr[N])
{
	int cInt=c;
	int i=N-1;
	int num=0;//计算c的二进制码中1的个数
	int n=0;

	vStr[i]='\0';
	i--;
	while(c>0)
	{
		n=c%2;
		vStr[i]=n+'0';
		if(n==1)//累计1的个数
			num++;
		i--;
		c/=2;
	}

	while(i>0)
	{
		vStr[i]='0';
		i--;
	}

	if(num%2==0)
	{
		vStr[i]='1';
	}
	else
	{
		vStr[i]='0';
	}
	return OK;
}
//奇校验一个字符串的各位并输出
Status verifyStrO(char str[M])
{
	int i=0;
	char strV[N];
	while(str[i]!='\0')
	{
		verifyCharO(str[i],strV);
		printf("%s\n",strV);
		i++;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	char str[M];
	while(scanf("%s",str)!=EOF)
	{
		verifyStrO(str);
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