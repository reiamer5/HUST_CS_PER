#include<stdio.h>
#include<string.h>
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
#define N 7

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1120：全排列
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3530解决：881
题目描述：
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
输入：
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出：
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入：
abc
样例输出：
abc
acb
bac
bca
cab
cba
提示：
每组样例输出结束后要再输出一个回车。
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7843-1-1.html

*/
Boolean visited[N];
int strLen;

//检测放置的位置是否合法
//调用函数会超时
Boolean check(int k)
{
	if(visited[k]==TRUE)
		return FALSE;
	return TRUE;
}
Status permutation(char str[N])
{
	int index[N];
	int i=0,k=0;
	char pstr[N];

	strLen=strlen(str);
	for(i=0;i<strLen;i++)
	{
		visited[i]=FALSE;
		index[i]=-1;
	}

	while(k>=0)
	{
		index[k]++;
		while(index[k]<=strLen-1&&visited[index[k]]==TRUE)//调用函数会超时
		{
			index[k]++;
		}

		if(index[k]<=strLen-1)
		{
			if(k==strLen-1)//找到一组解
			{
				for(i=0;i<strLen;i++)
				{
					pstr[i]=str[index[i]];	
				}
				pstr[i]='\0';
				printf("%s\n",pstr);
			}
			else
			{
				visited[index[k]]=TRUE;
				k++;
				index[k]=-1;
			}
		}
		else
		{
			k--;//回朔
			visited[index[k]]=FALSE;
		}

	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];

	while(scanf("%s",str)!=EOF)//while 1#
	{
		permutation(str);
		printf("\n");
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
