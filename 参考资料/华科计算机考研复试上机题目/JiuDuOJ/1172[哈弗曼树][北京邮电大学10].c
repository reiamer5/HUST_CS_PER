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
#define N 1100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1172：哈夫曼树
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5170解决：2220
题目描述：
哈夫曼树，第一行输入一个数n，表示叶结点的个数。需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，
题目需要输出所有结点的值与权值的乘积之和。
输入：
输入有多组数据。
每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。
输出：
输出权值。
样例输入：
5  
1 2 2 5 9
样例输出：
37
来源：
2010年北京邮电大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7895-1-1.html
*/
int data[N];
int comp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int hfmWeight(int n)
{
	int sum=0;
	int i=0;
	for(i=0;i<n-1;i++)
	{
		qsort(data+i,n-i,sizeof(int),comp);
		data[i+1]=data[i]+data[i+1];	
		sum+=data[i+1];
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;

	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		data[i]=0;
		printf("%d\n",hfmWeight(n));
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