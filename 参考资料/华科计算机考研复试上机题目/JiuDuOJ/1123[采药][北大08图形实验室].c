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

#define M 1000
#define N 1005

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1123：采药
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2111解决：1031
题目描述：
辰辰是个很有潜能、天资聪颖的孩子，他的梦想是称为世界上最伟大的医师。
为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。
医师把他带到个到处都是草药的山洞里对他说：
"孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。
我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。"
如果你是辰辰，你能完成这个任务吗？
输入：
输入的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），T代表总共能够用来采药的时间，M代表山洞里的草药的数目。
接下来的M行每行包括两个在1到100之间（包括1和100）的的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出：
可能有多组测试数据，对于每组数据，
输出只包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。 
样例输入：
70 3
71 100
69 1
1 2
样例输出：
3
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7846-1-1.html
*/
/*
int table[N][2]:采摘某株草药的时间和这株草药的价值
int category:药物的种数
int limit:时间限制
*/
int handleFunction(int table[M][2],int category,int limit)
{
	int bonus[N];
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		bonus[i]=0;
	}
	for(j=0;j<category;j++)
	{
		for(i=limit;i>=table[j][0];i--)
		{
			if(bonus[i-table[j][0]]+table[j][1]>bonus[i])
				bonus[i]=bonus[i-table[j][0]]+table[j][1];
		}
	}
	return bonus[limit];
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int table[M][2];
	int category;
	int limit;
	int i=0;
	while(scanf("%d %d",&limit,&category)!=EOF)//while 1#
	{
		for(i=0;i<category;i++)
		{
			scanf("%d %d",&table[i][0],&table[i][1]);
		}
		printf("%d\n",handleFunction(table,category,limit));
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
