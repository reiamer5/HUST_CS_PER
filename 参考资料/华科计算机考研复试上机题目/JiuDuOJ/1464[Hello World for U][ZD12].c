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
题目1464：Hello World for U
时间限制：1 秒内存限制：128 兆特殊判题：否提交：3896解决：1087
题目描述：
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, 
"helloworld" can be printed as:
h    d
e     l
l      r
lowo

That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, 
then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. 
And more, we would like U to be as squared as possible -- that is, it must be satisfied that
 n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
输入：
There are multiple test cases.Each case contains one string with no less than 5 and no more than 80 characters in a line. 
The string contains no white space.
输出：
For each test case, print the input string in the shape of U as specified in the description.
样例输入：
helloworld!
ac.jobdu.com
样例输出：
h   !
e   d
l   l
lowor
a    m
c    o
.    c
jobdu.
*/


Status printStr(char str[N])
{

	int i=0;
	int j=0;
	int k=0;
	int n=strlen(str);
	int vertical=(n+2)/3;//打印竖线空白的次数
	int space=n-2*vertical;

	//打印两边
	for(j=0;j<vertical-1;j++)
	{	
		printf("%c",str[i]);//第一个字符
		for(k=0;k<space;k++)
		{
			printf(" ");//中间的空白	
		}
		printf("%c\n",str[n-1-i]);//最后一个字符
		i++;
	}
	for(j=0;j<space+2;j++)
	{
		printf("%c",str[i++]);
	}
	printf("\n");
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	while(scanf("%s",str)!=EOF)//while 1#
	{
		printStr(str);
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