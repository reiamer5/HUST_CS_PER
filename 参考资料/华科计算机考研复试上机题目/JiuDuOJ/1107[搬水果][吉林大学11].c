#include<stdio.h>
#include<math.h>
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
题目1107：搬水果
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4328解决：1421
题目描述：
    在一个果园里，小明已经将所有的水果打了下来，并按水果的不同种类分成了若干堆，小明决定把所有的水果合成一堆。
	每一次合并，小明可以把两堆水果合并到一起，消耗的体力等于两堆水果的重量之和。当然经过 n‐1 次合并之后，就变成一堆了。
	小明在合并水果时总共消耗的体力等于每次合并所耗体力之和。
    假定每个水果重量都为 1，并且已知水果的种类数和每种水果的数目，你的任务是设计出合并的次序方案，使小明耗费的体力最少，
	并输出这个最小的体力耗费值。例如有 3 种水果，数目依次为 1，2，9。可以先将 1，2 堆合并，新堆数目为3，耗费体力为 3。
	然后将新堆与原先的第三堆合并得到新的堆，耗费体力为 12。所以小明总共耗费体力=3+12=15，可以证明 15 为最小的体力耗费值。
输入：
    每组数据输入包括两行,第一行是一个整数 n(1<=n<=10000),表示水果的种类数，如果 n 等于 0 表示输入结束，且不用处理。
	第二行包含 n 个整数，用空格分隔，第 i 个整数(1<=ai<=1000)是第 i 种水果的数目。
输出：
对于每组输入，输出一个整数并换行，这个值也就是最小的体力耗费值。输入数据保证这个值小于 2^31。
样例输入：
3
9 1 2
0
样例输出：
15
来源：
2011年吉林大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7830-1-1.html
9
12 234 34 5 56 654 3 6 5
*/

int data[N];
int num=0;
int comp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

Status selectSort(int *a,int n)
{
	int i=0;
	int e=a[0];
	int temp=0;
	while(i<n-1&&a[i+1]<e)
	{
		a[i]=a[i+1];
		i++;
	}
	a[i]=e;
	return OK;
}
int handleFunction()
{
	int i=0;
	int sum=0;
	if(num==1)
		return data[0];
	qsort(data,num,sizeof(int),comp);
	while(i<num-1)
	{
		data[i+1]=data[i]+data[i+1];
		sum+=data[i+1];	
		i++;
		selectSort(data+i,num-i);
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	while(scanf("%d",&num),num)//while 1#
	{
		for(i=0;i<num;i++)
		{
			scanf("%d",data+i);
		}
		printf("%d\n",handleFunction());
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