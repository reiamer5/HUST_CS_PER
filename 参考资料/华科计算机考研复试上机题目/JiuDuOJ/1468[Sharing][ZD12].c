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
#define N 100000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1468：Sharing
时间限制：1 秒内存限制：128 兆特殊判题：否提交：2688解决：551
题目描述：
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, 
we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are 
stored as showed in Figure 1.

Figure 1
You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).
输入：
For each case, the first line contains two addresses of nodes and a positive N (<= 10^5), where the two addresses are
 the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit
 positive integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen 
from {a-z, A-Z}, and Next is the position of the next node.
输出：
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common
 suffix, output "-1" instead.
样例输入：
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
样例输出：
67890
-1
*/

int NodeList[N];

int handleFunction(int a,int b)
{
	int lengthA=0;
	int lengthB=0;
	int diff=0;
	int pa=a;
	int pb=b;
	int pc=0;
	int pd=0;

	while(pa!=-1)//求第一条链的长度
	{
		pa=NodeList[pa];
		lengthA++;
	}
	while(pb!=-1)//求第二条链的长度
	{
		pb=NodeList[pb];
		lengthB++;
	}

	if(lengthA>lengthB)//pc指向比较长的那条链的头结点
	{
		pc=a;
		pd=b;
		diff=lengthA-lengthB;
	}
	else 
	{
		pc=b;
		pd=a;
		diff=lengthB-lengthA;
	}

	while(diff>0)
	{
		pc=NodeList[pc];
		diff--;
	}
	while(pc!=pd)
	{
		pc=NodeList[pc];
		pd=NodeList[pd];
	}

	return pc;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	int n=0;
	int a=0,b=0;
	int c=0,d=0;
	int comm=0;
	char ch;
	while(scanf("%d %d %d",&a,&b,&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %c %d",&c,&ch,&d);
			NodeList[c]=d;
		}
		
		comm=handleFunction(a,b);
		if(comm>=0)
			printf("%05d\n",comm);
		else
			printf("%d\n",comm);
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