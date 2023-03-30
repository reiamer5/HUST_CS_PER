#include<stdio.h>
//#include<string.h>
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
题目1473：二进制数
时间限制：1 秒内存限制：128 兆特殊判题：否提交：5498解决：1523
题目描述：
　　大家都知道，数据在计算机里中存储是以二进制的形式存储的。
　　有一天，小明学了C语言之后，他想知道一个类型为unsigned int 类型的数字，存储在计算机中的二进制串是什么样子的。
　　你能帮帮小明吗？并且，小明不想要二进制串中前面的没有意义的0串，即要去掉前导0。
输入：
第一行，一个数字T（T<=1000），表示下面要求的数字的个数。
接下来有T行，每行有一个数字n（0<=n<=10^8），表示要求的二进制串。
输出：
输出共T行。每行输出求得的二进制串。
样例输入：
5
23
535
2624
56275
989835
样例输出：
10111
1000010111
101001000000
1101101111010011
11110001101010001011
来源：
2012年北京邮电大学计算机研究生机试真题


*/
Status dTob(unsigned int n,char str[N])
{
	int k=0;
	int low=0,high=0;
	char c;
	if(n==0)
	{
		str[0]='0';
		str[1]='\0';
		return OK;
	}
	while(n>0)//将十进制数n转换为二进制数  并将转换后的结果存放在str中
	{
		str[k]=n%2+'0';
		n=n>>1;
		k++;
	}
	str[k]='\0';
	//调整顺序
	high=k-1;
	while(low<high)
	{
		c=str[low];
		str[low]=str[high];
		str[high]=c;
		low++;
		high--;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,D=0;
	char str[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&D);
			dTob(D,str);
			printf("%s\n",str);
		}
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