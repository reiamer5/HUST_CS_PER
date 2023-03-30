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
#define N 20

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1151：位操作练习
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1524解决：842
题目描述：
给出两个不大于65535的非负整数，判断其中一个的16位二进制表示形式，是否能由另一个的16位二进制表示形式经过循环左移若干位而得到。

循环左移和普通左移的区别在于：最左边的那一位经过循环左移一位后就会被移到最右边去。比如：
1011 0000 0000 0001 经过循环左移一位后，变成 0110 0000 0000 0011, 若是循环左移2位，则变成 1100 0000 0000 0110
输入：
第一行是个整数n, 0 < n < 300000,表示后面还有n行数据
后面是n行，每行有两个不大于65535的非负整数
输出：
对于每一行的两个整数，输出一行，内容为YES或NO
样例输入：
4
2 4
9 18
45057 49158
7 12
样例输出：
YES
YES
YES
NO
来源：
2010年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7874-1-1.html

*/
Status judge(int a,int b)
{
	char str1[N];
	char str2[N];
	int len1=0;
	int len2=0;
	int i=0,n=0;

	char c;

	if(a==b)
	{
		printf("YES\n");
		return OK;
	}
	while(a>0)
	{
		str1[i++]=a%2+'0';
		a/=2;
	}
	while(i<16)
	{
		str1[i++]='0';
	}
	str1[i]='\0';
	len1=i;

	i=0;
	while(b>0)
	{
		str2[i++]=b%2+'0';
		b/=2;
	}
	while(i<16)
	{
		str2[i++]='0';
	}
	str2[i]='\0';
	len2=i;
	if(strcmp(str1,str2)==0)
	{
		printf("YES\n");	
		return OK;
	}
//	printf("%s\n%s\n",str1,str2);
	n=16;
	while(n>0)
	{
		i=15;
		c=str1[i];
		while(i>0)
		{
			str1[i]=str1[i-1];
			i--;
		}
		str1[i]=c;
		if(strcmp(str1,str2)==0)
		{
			printf("YES\n");	
			return OK;
		}
		n--;
	}

	printf("NO\n");	
	return OK;

}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,a=0,b=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			judge(a,b);
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