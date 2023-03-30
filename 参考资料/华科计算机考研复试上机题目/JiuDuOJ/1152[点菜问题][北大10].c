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

#define M 120
#define N 1010

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1152：点菜问题
时间限制：1 秒内存限制：32 兆特殊判题：否提交：906解决：472
题目描述：
    北大网络实验室经常有活动需要叫外买，但是每次叫外买的报销经费的总额最大为C元，有N种菜可以点，经过长时间的点菜，
	网络实验室对于每种菜i都有一个量化的评价分数（表示这个菜可口程度），为Vi，每种菜的价格为Pi, 问如何选择各种菜，
	使得在报销额度范围内能使点到的菜的总评价分数最大。
    注意：由于需要营养多样化，每种菜只能点一次。
输入：
    输入的第一行有两个整数C（1 <= C <= 1000）和N（1 <= N <= 100），C代表总共能够报销的额度，N>代表能点菜的数目。
	接下来的N行每行包括两个在1到100之间（包括1和100）的的整数，分别表示菜的>价格和菜的评价分数。
输出：
    输出只包括一行，这一行只包含一个整数，表示在报销额度范围内，所点的菜得到的最大评价分数。
样例输入：
90 4
20 25
30 20
40 50
10 18
40 2
25 30
10 8
样例输出：
95
38
来源：
2010年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7875-1-1.html


*/
Status handleFunction(int data[M][2],int num,int limit)
{
	int i=0,j=0;
	int f[N];
	for(i=0;i<N;i++)
	{
		f[i]=0;
	}

	for(i=0;i<num;i++)
	{
		for(j=limit;j>=data[i][0];j--)
		{
			if(f[j-data[i][0]]+data[i][1]>f[j])
			{
				f[j]=f[j-data[i][0]]+data[i][1];
			}
		}
	}

	printf("%d\n",f[limit]);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0,j=0;
	int data[M][2];
	int num;
	int limit;
	while(scanf("%d %d",&limit,&num)!=EOF)//while 1#
	{
		for(i=0;i<num;i++)
		{
			scanf("%d %d",*(data+i),*(data+i)+1);
		}
		handleFunction(data,num,limit);
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