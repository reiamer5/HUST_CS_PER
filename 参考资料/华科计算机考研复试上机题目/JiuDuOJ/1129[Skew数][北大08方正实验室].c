#include<stdio.h>
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
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1129：Skew数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：653解决：496
题目描述：
在 skew binary表示中, 第 k 位的值xk表示xk*(2k+1-1)。 
每个位上的可能数字是0 或 1，最后面一个非零位可以是2, 
例如, 10120(skew) = 1*(25-1) + 0*(24-1) + 1*(23-1) + 2*(22-1) + 0*(21-1) = 31 + 0 + 7 + 6 + 0 = 44. 
前十个skew数是 0、1、2、10、11、12、20、100、101、以及102。
输入：
输入包含一行或多行，每行包含一个整数n。如果 n = 0 表示输入结束，否则n是一个skew数
输出：
可能有多组测试数据，对于每一个输入，
输出它的十进制表示。转换成十进制后， n 不超过 231-1 = 2147483647
样例输入：
10120
200000000000000000000000000000
10
1000000000000000000000000000000
11
100
11111000001110000101101102000
0
样例输出：
44
2147483646
3
2147483647
4
7
1041110737
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7852-1-1.html
九度Online Judge修改自HUSTOJ | 浙ICP备09099636号 | 九度Online Judge版权所有
*/
long skew(char *p)
{
	int strLen=strlen(p);
	long k=1<<strLen;

	long sum=0;	 
	while(*p!='\0')
	{
		if(*p=='1')
		{
			sum=sum+k-1;
		}
		else if(*p=='2')
		{
			sum=sum+(k<<1)-2;
		}
		k=k>>1;
		p++;
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	scanf("%s",str);
	while(strcmp(str,"0"))//while 1#
	{
		printf("%d\n",skew(str));
		scanf("%s",str);
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