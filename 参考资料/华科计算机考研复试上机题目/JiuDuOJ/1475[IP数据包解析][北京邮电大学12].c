#include<stdio.h>
#include<ctype.h>
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

//#define M 1000
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*

题目1475：IP数据包解析
时间限制：1 秒内存限制：128 兆特殊判题：否提交：3044解决：394
题目描述：
我们都学习过计算机网络，知道网络层IP协议数据包的头部格式如下：
　　 
　　其中IHL表示IP头的长度，单位是4字节；总长表示整个数据包的长度，单位是1字节。
　　传输层的TCP协议数据段的头部格式如下：
　　 
　　头部长度单位为4字节。
　　你的任务是，简要分析输入数据中的若干个TCP数据段的头部。 详细要求请见输入输出部分的说明。
输入：
第一行为一个整数T，代表测试数据的组数。
以下有T行，每行都是一个TCP数据包的头部分，字节用16进制表示，以空格隔开。数据保证字节之间仅有一个空格，且行首行尾没有多余的空白字符。
保证输入数据都是合法的。
输出：
对于每个TCP数据包，输出如下信息：
Case #x，x是当前测试数据的序号，从1开始。
Total length = L bytes，L是整个IP数据包的长度，单位是1字节。
Source = xxx.xxx.xxx.xxx，用点分十进制输出源IP地址。输入数据中不存在IPV6数据分组。
Destination = xxx.xxx.xxx.xxx，用点分十进制输出源IP地址。输入数据中不存在IPV6数据分组。
Source Port = sp，sp是源端口号。
Destination Port = dp，dp是目标端口号。
对于每个TCP数据包，最后输出一个多余的空白行。
具体格式参见样例。
请注意，输出的信息中，所有的空格、大小写、点符号、换行均要与样例格式保持一致，并且不要在任何数字前输出多余的前导0，
也不要输出任何不必要的空白字符。
样例输入：
2
45 00 00 34 7a 67 40 00 40 06 63 5a 0a cd 0a f4 7d 38 ca 09 cd f6 00 50 b4 d7 ae 1c 9b cf f2 40 80 10 ff 3d fd d0 00 00 01 01 08 0a 32 53 7d fb 5e 49 4e c8
45 00 00 c6 56 5a 40 00 34 06 e0 45 cb d0 2e 01 0a cd 0a f4 00 50 ce 61 e1 e9 b9 ee 47 c7 37 34 80 18 00 b5 81 8f 00 00 01 01 08 0a 88 24 fa c6 32 63 cd 8d

样例输出：
Case #1
Total length = 52 bytes
Source = 10.205.10.244
Destination = 125.56.202.9
Source Port = 52726
Destination Port = 80

Case #2
Total length = 198 bytes
Source = 203.208.46.1
Destination = 10.205.10.244
Source Port = 80
Destination Port = 52833
来源：
2012年北京邮电大学计算机研究生机试真题

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
//将十六进制字符转化为对应的十进制数
int xTodC(char c)
{
	if(isdigit(c))
	{
		return c-'0';
	}
	else if(isxdigit(c))
	{
		if(islower(c))
		{
			return c-'a'+10;
		}
		else if(isupper(c))
		{
			return c-'A'+10;
		}
	}
}

//将指定下标范围startIndex至endIndex的十六进制字符串转化为对应的十进制数
int xTodRange(const char *str,const int startIndex,const int endIndex)
{
	int sum=0;
	int k=0;
	int i=endIndex;
	while(i>=startIndex)
	{
		sum+=xTodC(str[i])<<k;
		k+=4;
		i--;
	}
	return sum;
}
Status analyseIP(ElemType str[N])
{
	int i=0,j=0;
	int headLen=0;//首部长度
	int totalLen=0;//整个IP数据包的长度
	deleteChar(str,' ');//删除分析字符串对象中的空格

	headLen=xTodC(str[1])*4;//求首部长度,单位为字节故乘以4
	totalLen=xTodRange(str,4,7);//求总长度
	printf("Total length = %d bytes\n",totalLen);
	printf("Source = %d.%d.%d.%d\n",xTodRange(str,24,25),xTodRange(str,26,27),xTodRange(str,28,29),xTodRange(str,30,31));
	printf("Destination = %d.%d.%d.%d\n",xTodRange(str,32,33),xTodRange(str,34,35),xTodRange(str,36,37),xTodRange(str,38,39));
	printf("Source Port = %d\n",xTodRange(str,headLen*2,headLen*2+3));
	printf("Destination Port = %d\n",xTodRange(str,headLen*2+4,headLen*2+7));
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	ElemType str[N];
	scanf("%d",&n);//while 1#
	getchar();
	for(i=0;i<n;i++)
	{			
		gets(str);			
		printf("Case #%d\n",i+1);			
		analyseIP(str);
		printf("\n");
	}
	//	getchar();

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
