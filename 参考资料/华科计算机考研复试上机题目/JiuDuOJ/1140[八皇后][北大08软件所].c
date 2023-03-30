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
#define M 9
#define N 8

/*************************题目说明********************/
/*
题目1140：八皇后
时间限制：1 秒内存限制：32 兆特殊判题：否提交：665解决：427
题目描述：
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），
使它们谁也不能被吃掉！这就是著名的八皇后问题。 
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。
已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
输入：
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
输出：
输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
样例输入：
2
1
92
样例输出：
15863724
84136275
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7863-1-1.html

*/

int pos[M];//各个皇后放置的位置

//检测放置的位置是否合法
Boolean check(int k)
{
	int i=1;
	while(i<k)
	{
		if(abs(pos[i]-pos[k])==abs(i-k) || pos[i]==pos[k])
		{
			return FALSE;
		}
		i++;
	}
	return TRUE;
}

Status backdate(int n)
{
	int i=0,k=1;
	int count=0;

	for(i=1;i<=N;i++)
	{
		pos[i]=0;//初始化各位置
	}
	while(count<n)
	{
		pos[k]=pos[k]+1;
		while(check(k)==FALSE&&pos[k]<=N)
		{
			pos[k]=pos[k]+1;
		}
		if(pos[k]<=N)
		{	
			if(k==N)
			{
				count++;
			}
			else
			{
				k++;
				pos[k]=0;
			}
		}
		else
		{
			k--;
		}
	
	}
	for(i=1;i<=N;i++)
		printf("%d",pos[i]);
	printf("\n");
	return OK;
}



//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	scanf("%d",&n);
	while(n>0)//while 1#
	{
		scanf("%d",&i);
		backdate(i);
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