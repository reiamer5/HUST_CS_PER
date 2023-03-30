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
题目1146：Flipping Pancake
时间限制：1 秒内存限制：32 兆特殊判题：是提交：226解决：99
题目描述：
    We start with a stack n of pancakes of distinct sizes. The problem is to convert the stack to one in which the pancakes 
	are in size order with the smallest on the top and the largest on the bottom. To do this, we are allowed to flip the top 
	k pancakes over as a unit (so the k-th pancake is now on top and the pancake previously on top is now in the k-th position).
    For example: This problem is to write a program, which finds a sequence of at most (2n - 3) flips, which converts a given 
	stack of pancakes to a sorted stack. 
输入：
    Each line of the input gives a separate data set as a sequence of numbers separated by spaces. The first number on each 
	line gives the number, N, of pancakes in the data set. The input ends when N is 0 (zero) with no other data on the line. 
	The remainder of the data set are the numbers 1 through N in some order giving the initial pancake stack.
    The numbers indicate the relative sizes of the pancakes. N will be, at most, 30. 
输出：
     For each data set, the output is a single-space separated sequence of numbers on a line. The first number on each line, 
	 K, gives the number of flips required to sort the pancakes. This number is followed by a sequence of K numbers, 
	 each of which gives the number of pancakes to flip on the corresponding sorting step. There may be several correct
	 solutions for some datasets. For instance 3 3 2 3 is also a solution to the first problem below. 
样例输入：
3 1 3 2
5 4 3 2 5 1
0
样例输出：
3 2 3 2 
3 3 4 5 
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7869-1-1.html
九度Online Judge修改自HUSTOJ | 浙ICP备09099636号 | 九度Online Judge版权所有


*/

Status exchange(int data[N],int index)
{
	int i=0;
	int temp=0;
	while(i<index)
	{
		temp=data[i];
		data[i]=data[index];
		data[index]=temp;
		i++;
		index--;
	}
	return OK;
}
Status handleFunction(int data[N],int num)
{
	int i=0,j=0;
	int sq[N*10];
	int size=0;
	
	for(i=num-1;i>=0;i--)
	{
		if(data[i]==i+1)
			continue;
		for(j=1;j<i;j++)
		{
			if(data[j]==i+1)
			{
				exchange(data,j);
				sq[size++]=j+1;
			}
		}
		exchange(data,i);
		sq[size++]=i+1;
	}
	if(size>0)
	{
		printf("%d ",size);
		for(i=0;i<size-1;i++)
		{
			printf("%d ",sq[i]);
		}
		printf("%d\n",sq[i]);
	}
	else
	{
		printf("0\n");
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i;
	int data[N];
	scanf("%d",&n);
	while(n!=0)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		handleFunction(data,n);
		scanf("%d",&n);
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