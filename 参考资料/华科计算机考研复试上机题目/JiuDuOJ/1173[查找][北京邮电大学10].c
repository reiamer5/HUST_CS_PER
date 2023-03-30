#include<stdio.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 1000

/*************************题目说明********************/
/*
题目1173：查找
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4281解决：2383
题目描述：
输入数组长度 n 
输入数组      a[1...n] 
输入查找个数m 
输入查找数字b[1...m] 
 
输出 YES or NO  查找有则YES 否则NO 。
输入：
输入有多组数据。
每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1<=m<=n<=100）。
输出：
如果在n个数组中输出YES否则输出NO。
样例输入：
5
1 5 2 4 3
3
2 5 6
样例输出：
YES
YES
NO
来源：
2010年北京邮电大学网院研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7896-1-1.html
*/

int data[N];
int length;
Boolean searchX(int x)
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if(data[i]==x)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int m=0,n=0;
	int i=0,j=0;
	int search[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		length=n;

		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}

		scanf("%d",&m);

		for(i=0;i<m;i++)
		{
			scanf("%d",search+i);
		}

		for(i=0;i<m;i++)
		{
			if(TRUE==searchX(search[i]))
				printf("YES\n");
			else 
				printf("NO\n");
		}
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