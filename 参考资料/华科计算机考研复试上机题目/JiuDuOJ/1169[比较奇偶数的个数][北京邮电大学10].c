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
#define N 2000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目描述：
第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。
输入：
输入有多组数据。
每组输入n，然后输入n个整数（1<=n<=1000）。
输出：
如果偶数比奇数多，输出NO，否则输出YES。
样例输入：
5
1 5 2 4 3
样例输出：
YES
来源：
2010年北京邮电大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7892-1-1.html


*/
Status countOE(int data[N],int n)
{
	int i=0;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(data[i]%2==0)
			count++;
		else
			count--;
	}
	if(count>0)
		printf("NO\n");
	else
		printf("YES\n");
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int n=0;
	int i=0,j=0;
	int data[N];
	int k=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		countOE(data,n);
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