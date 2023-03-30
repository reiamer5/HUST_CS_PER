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
#define N 100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1126：打印极值点下标
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3437解决：1261
题目描述：
在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数，
或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。
输入：
每个案例的输入如下：
有2×n+1行输入：第一行是要处理的数组的个数n；
对其余2×n行，第一行是此数组的元素个数k(4<k<80)，第二行是k个整数，每两个整数之间用空格分隔。
输出：
每个案例输出为n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔。
样例输入：
3
10
10 12 12 11 11 12 23 24 12 12
15
12 12 122 112 222 211 222 221 76 36 31 234 256 76 76 
15
12 14 122 112 222 222 222 221 76 36 31 234 256 76 73
样例输出：
0 7
2 3 4 5 6 10 12
0 2 3 10 12 14
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7849-1-1.html
*/

Status mValue(int value[N],int k)
{
	int mIndex[N];
	int size=0;
	int i=0;

	if(value[0]!=value[1])
	{
		mIndex[size++]=0;
	}
	
	for(i=1;i<k-1;i++)
	{
		if((value[i]>value[i+1]&&value[i]>value[i-1])||
		   (value[i]<value[i+1]&&value[i]<value[i-1]))
		{
			mIndex[size++]=i;
		}
	}
	
	if(value[k-2]!=value[k-1])
	{
		mIndex[size++]=k-1;
	}

	if(size>0)
	{
		for(i=0;i<size-1;i++)
		{
			printf("%d ",mIndex[i]);
		}
		printf("%d",mIndex[i]);
	}
	printf("\n");
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,k=0;
	int value[N];
	scanf("%d",&n);
	while(n>0)//while 1#
	{
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%d",value+i);		 
		}
		mValue(value,k);
		n--;
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