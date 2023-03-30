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
#define N 10

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1117：整数奇偶排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2861解决：835
题目描述：
输入10个整数，彼此以空格分隔。重新排序以后输出(也按空格分隔)，要求:
1.先输出其中的奇数,并按从大到小排列；
2.然后输出其中的偶数,并按从小到大排列。
输入：
任意排序的10个整数（0～100），彼此以空格分隔。
输出：
可能有多组测试数据，对于每组数据，按照要求排序后输出，由空格分隔。
样例输入：
4 7 3 13 11 12 0 47 34 98
样例输出：
47 13 11 7 3 0 4 12 34 98
提示：
1. 测试数据可能有很多组，请使用while(cin>>a[0]>>a[1]>>...>>a[9])类似的做法来实现;
2. 输入数据随机，有可能相等。
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7840-1-1.html
*/

int comp1(const void *a,const void *b)
{
	return *((int*)a)-*((int*)b);
}
int comp2(const void *a,const void *b)
{
	return comp1(b,a);
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,o=0,e=0;
	int Od[N];
	int Ev[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		o=e=0;
		if(n%2==0)
			Ev[e++]=n;
		else
			Od[o++]=n;
		for(i=0;i<9;i++)
		{
			scanf("%d",&n);
			if(n%2==0)
				Ev[e++]=n;
			else
				Od[o++]=n;
		}
		qsort(Od,o,sizeof(int),comp2);
		qsort(Ev,e,sizeof(int),comp1);

		for(i=0;i<o-1;i++)
		{
			printf("%d ",Od[i]);
		}
		if(o>0&&e>0)
			printf("%d ",Od[i]);
		else if(o>0)
			printf("%d\n",Od[i]);
		for(i=0;i<e-1;i++)
		{
			printf("%d ",Ev[i]);
		}
		if(e>0)
			printf("%d\n",Ev[i]);	
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