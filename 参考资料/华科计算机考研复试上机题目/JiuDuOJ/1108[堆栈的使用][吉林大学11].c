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
#define N 10100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1108：堆栈的使用
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5448解决：1594
题目描述：
    堆栈是一种基本的数据结构。堆栈具有两种基本操作方式，push 和 pop。Push一个值会将其压入栈顶，而 pop 则会将栈顶的值弹出。
	现在我们就来验证一下堆栈的使用。
输入：
     对于每组测试数据，第一行是一个正整数 n，0<n<=10000(n=0 结束)。而后的 n 行，
	 每行的第一个字符可能是'P’或者'O’或者'A’；如果是'P’，后面还会跟着一个整数，表示把这个数据压入堆栈；
	 如果是'O’，表示将栈顶的值 pop 出来，如果堆栈中没有元素时，忽略本次操作；
	 如果是'A’，表示询问当前栈顶的值，如果当时栈为空，则输出'E'。堆栈开始为空。
输出：
    对于每组测试数据，根据其中的命令字符来处理堆栈；并对所有的'A’操作，输出当时栈顶的值，每个占据一行，
	如果当时栈为空，则输出'E’。当每组测试数据完成后，输出一个空行。
样例输入：
3
A
P 5
A
4
P 3
P 6
O 
A
0
样例输出：
E
5

3
*/
int data[N];
int length=0;
Status handleFunction(char c,int n)
{
	if(c=='P')
	{
		data[length++]=n;
	}
	else if(c=='O')
	{
		if(length>0)
		{
			length--;
		}
	}
	else if(c=='A')
	{
		if(length>0)
		{
			printf("%d\n",data[length-1]);
		}
		else
		{
			printf("E\n");
		}
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0,x;
	int i=0;
	char c;
	while(scanf("%d",&n),n)//while 1#
	{
		length=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",&c);
			if(c=='P')
			{
				scanf("%d",&x);
			}
			handleFunction(c,x);
		}
		printf("\n");
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