#include<stdio.h>
//#include<string.h>
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
#define N 1005

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1174：查找第K小数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5288解决：2136
题目描述：
查找一个数组的第K小的数，注意同样大小算一样大。 
如  2 1 3 4 5 2 第三小数为3。
输入：
输入有多组数据。
每组输入n，然后输入n个整数(1<=n<=1000)，再输入k。
输出：
输出第k小的整数。
样例输入：
6
2 1 3 5 2 2
3
样例输出：
3
来源：
2010年北京邮电大学网院研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7897-1-1.html

*/
int data[N];
int comp(const void * a,const void * b)
{
	return *((int*)a)-*((int*)b);
}
int search(int k,int n)
{
	int i=0;
	int count=0;

	qsort(data,n,sizeof(int),comp);

	while(i<n&&count<k)
	{	
		count++;
		while(i<n-1&&data[i]==data[i+1])
		{
			i++;
		}
		i++;
	}
	return data[i-1];//没有查询到
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,k=0;
 
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		scanf("%d",&k);
		printf("%d\n",search(k,n));
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