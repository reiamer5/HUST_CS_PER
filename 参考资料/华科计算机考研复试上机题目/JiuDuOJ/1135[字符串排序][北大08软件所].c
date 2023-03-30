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

#define M 50
#define N 120

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1135：字符串排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1376解决：719
题目描述：
先输入你要输入的字符串的个数。然后换行输入该组字符串。每个字符串以回车结束，每个字符串少于一百个字符。
如果在输入过程中输入的一个字符串为"stop"，也结束输入。
然后将这输入的该组字符串按每个字符串的长度，由小到大排序，按排序结果输出字符串。
输入：
字符串的个数，以及该组字符串。每个字符串以'\n'结束。如果输入字符串为"stop"，也结束输入.
输出：
可能有多组测试数据，对于每组数据，
将输入的所有字符串按长度由小到大排序输出(如果有"stop"，不输出"stop")。
样例输入：
5
sky is grey
cold
very cold
stop
3
it is good enough to be proud of
good
it is quite good
样例输出：
cold
very cold
sky is grey
good
it is quite good
it is good enough to be proud of
提示：
根据输入的字符串个数来动态分配存储空间（采用new()函数）。每个字符串会少于100个字符。
测试数据有多组，注意使用while()循环输入。
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7858-1-1.html
*/
char data[M][N];
int count=0;
int comp(const void * s1,const void * s2)
{
	return strlen((char*)s1)-strlen((char*)s2);
}
Status handleFunction()
{	
//	printf("%d\n",count);
	qsort(data,count,sizeof(data[0]),comp);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	while(scanf("%d",&count)!=EOF)//while 1#
	{
		getchar();
		for(i=0;i<count;i++)
		{
			gets(data[i]);
			if(strcmp(data[i],"stop")==0)
			{
				count=i;
				break;
			}
		}
		handleFunction();
		for(i=0;i<count;i++)
		{
			printf("%s\n",data[i]);
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