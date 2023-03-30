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
#define N 1500

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1176：树查找
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3849解决：1648
题目描述：
有一棵树，输出某一深度的所有节点，有则输出这些节点，无则输出EMPTY。该树是完全二叉树。
输入：
输入有多组数据。
每组输入一个n(1<=n<=1000)，然后将树中的这n个节点依次输入，再输入一个d代表深度。
输出：
输出该树中第d层得所有节点，节点间用空格隔开，最后一个节点后没有空格。
样例输入：
4
1 2 3 4
2
样例输出：
2 3
来源：
2010年北京邮电大学网院研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7899-1-1.html
*/

Status kLevel(int data[N],int n,int k)
{
	int limit= n>((int)pow(2,k)-1)?((int)pow(2,k)-1):n;
	int i=0;
	for(i=((int)pow(2,k-1));i<limit;i++)
	{
		printf("%d ",data[i]);
	}
	printf("%d\n",data[i]);
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
		for(i=1;i<=n;i++)
		{
			scanf("%d",data+i);
		}
		scanf("%d",&k);
		kLevel(data,n,k);
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