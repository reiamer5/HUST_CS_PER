#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//#define M 1000
#define N 1500

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1178：复数集合
时间限制：1 秒内存限制：32 兆特殊判题：否提交：7313解决：1339
题目描述：
    一个复数（x+iy）集合，两种操作作用在该集合上：
    1、Pop 表示读出集合中复数模值最大的那个复数，如集合为空 输出  empty  ，不为空就输出最大的那个复数并且从集合中删除那个复数，
		再输出集合的大小SIZE；
    2 Insert a+ib  指令（a，b表示实部和虚部），将a+ib加入到集合中 ，输出集合的大小SIZE；
		最开始要读入一个int n，表示接下来的n行每一行都是一条命令。
输入：
输入有多组数据。
每组输入一个n(1<=n<=1000)，然后再输入n条指令。
输出：
根据指令输出结果。
样例输入：
3
Pop
Insert 1+i2
Pop
样例输出：
empty
SIZE = 1
1+i2
SIZE = 0
提示：
模相等的输出b较小的复数。
a和b都是非负数。
来源：
2011年北京邮电大学网院研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7901-1-1.html
20
Insert 4+i74
Insert 51+i74
Insert 41+i2
Insert 333+i27
Insert 7+i7
Insert 1+i11
Insert 10+i4

*/

//定义复数节点
typedef struct Complex
{
	int a;
	int b;
}Complex;

typedef struct SQStack
{
	Complex data[N];
	int length;
}SQStack;
SQStack S;//定义复数栈
char str[100];

int comp(const void* A,const void * B)
{
	int model= (*((Complex*)A)).a*(*((Complex*)A)).a+
		(*((Complex*)A)).b*(*((Complex*)A)).b-
		(*((Complex*)B)).a*(*((Complex*)B)).a-
		(*((Complex*)B)).b*(*((Complex*)B)).b;
	if(model==0)
	{
		return (*((Complex*)B)).b-(*((Complex*)A)).b;
	}
	else
	{
		return model;
	}
}

Status Pop()
{
	if(S.length<1)
	{
		printf("empty\n");
	}
	else
	{
		qsort(S.data,S.length,sizeof(Complex),comp);
		
		printf("%d+i%d\n",(S.data[S.length-1]).a,(S.data[S.length-1]).b);	
		S.length--;
		printf("SIZE = %d\n",S.length);
	}

	return OK;
}

Status Push(Complex e)//Insert a+ib
{
	S.data[S.length]=e;
	S.length++;
	printf("SIZE = %d\n",S.length);
	return OK;
}

Status handleFunction()
{
	int i=0,k=0,sum=0;
	int a=0,b=0;
	Complex e;
	if(str[0]=='P')
	{
		return Pop();
	}
	else if(str[0]=='I')//Insert 1+i2
	{
		
		while(str[i]<'0'||str[i]>'9')//跳出非数字部分
		{
			i++;
		
		}
		while(str[i]>='0'&&str[i]<='9')//提取命令中复数的实数部分
		{
			k=str[i]-'0';
			sum=10*sum+k;	
			i++;
		}
		a=sum;
		sum=0;
		while(str[i]<'0'||str[i]>'9')//跳出非数字部分
		{
			i++;
		}
		while(str[i]>='0'&&str[i]<='9')//提取命令中复数的虚数部分
		{
			k=str[i]-'0';
			sum=10*sum+k;
			i++;
		}
		b=sum;
		sum=0;
		e.a=a;
		e.b=b;
		Push(e);//入栈
		//printf("%d-- %d\n",a,b);
		return OK;
	}
	return OK;
	
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
//	char str[100];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		getchar();
		S.length=0;
		for(i=0;i<n;i++)
		{
			gets(str);
			handleFunction();
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