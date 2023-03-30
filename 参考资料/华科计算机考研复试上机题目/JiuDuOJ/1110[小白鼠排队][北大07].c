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

typedef int ElemType;

#define M 200
#define N 20

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1110：小白鼠排队
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1526解决：926
题目描述：
N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。
帽子的颜色用"red"，"blue"等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
输入：
多案例输入，每个案例的输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于100的正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。
注意：白鼠的重量各不相同。
输出：
每个案例按照白鼠的重量从大到小的顺序输出白鼠的帽子颜色。
样例输入：
3
30 red
50 blue
40 green
样例输出：
blue
green
red
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：

*/
typedef struct Mouse
{
	int weight;
	char color[N];
}Mouse;
Mouse mice[M];
int count=0;
int comp(const void *A,const void *B)
{
	return (*((Mouse*)B)).weight-(*((Mouse*)A)).weight;
}

Status sortM()
{
	int i=0;
	qsort(mice,count,sizeof(Mouse),comp);
	for(i=0;i<count;i++)
	{
		printf("%s\n",mice[i].color);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	while(scanf("%d",&count)!=EOF)//while 1#
	{
		for(i=0;i<count;i++)
		{
			scanf("%d%s",&(mice[i].weight),&(mice[i].color));
		}
		sortM();
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