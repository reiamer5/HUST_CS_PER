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
#define N 300

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1156：谁是你的潜在朋友
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4383解决：2030
题目描述：
    "臭味相投"--这是我们描述朋友时喜欢用的词汇。两个人是朋友通常意味着他们存在着许多共同的兴趣。然而作为一个宅男，
	你发现自己与他人相互了解的机会并不太多。幸运的是，你意外得到了一份北大图书馆的图书借阅记录，于是你挑灯熬夜地编程，
	想从中发现潜在的朋友。
    首先你对借阅记录进行了一番整理，把N个读者依次编号为1,2,…,N，把M本书依次编号为1,2,…,M。同时，按照"臭味相投"的原则，
	和你喜欢读同一本书的人，就是你的潜在朋友。你现在的任务是从这份借阅记录中计算出每个人有几个潜在朋友。
输入：
    每个案例第一行两个整数N,M，2 <= N ，M<= 200。接下来有N行，第i(i = 1,2,…,N)行每一行有一个数，表示读者i-1最喜欢的图书的编号P(1<=P<=M)
输出：
    每个案例包括N行，每行一个数，第i行的数表示读者i有几个潜在朋友。如果i和任何人都没有共同喜欢的书，则输出"BeiJu"（即悲剧，^ ^）
样例输入：
4  5
2
3
2
1
样例输出：
1
BeiJu
1
BeiJu
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7879-1-1.html
*/
Status searchFriend(int data[N],int num)
{
	int count[N];
	int i=0;

	memset(count,0,N);

	for(i=0;i<num;i++)
	{
		count[data[i]]++;
	}
	for(i=0;i<num;i++)
	{
		if(count[data[i]]>1)
		{
			printf("%d\n",count[data[i]]-1);
		}
		else
		{
			printf("BeiJu\n");
		}
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int m,n=0;
	int i=0;
	int data[N];
	while(scanf("%d %d",&n,&m)!=EOF)//while 1#
	{
		memset(data,0,N);
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		searchFriend(data,n);
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