#include<stdio.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 5000
/*
题目1188：约瑟夫环
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1660解决：730
题目描述：
    N个人围成一圈顺序编号，从1号开始按1、2、3......顺序报数，报p者退出圈外，其余的人再从1、2、3开始报数，报p的人再退出圈外，以此类推。
    请按退出顺序输出每个退出人的原序号。
输入：
包括一个整数N(1<=N<=3000)及一个整数p。
输出：
测试数据可能有多组，对于每一组数据，
按退出顺序输出每个退出人的原序号。
样例输入：
7 3
样例输出：
3 6 2 7 5 1 4

*/

int choose(int num,int step)
{
	int Q[N];//队列
	int i=0;
	int current=0;//当前元素的下标
	int last=num-1;//访问的上一个元素的下标
	int count=step;//记录次数
	//初始化数组 让每个元素的值为其后继的下标
	if(num>N)
		return ERROR;
	for(i=0;i<num-1;i++)
	{
		Q[i]=i+1;
	}
	Q[num-1]=0;//首尾成环

	while(last!=current)
	{
		count--;
		if(0==count)
		{	
			printf("%d ",current+1);
			Q[last]=Q[current];	
			count=step;
			current=Q[current];
		}
		else
		{
			last=current;
			current=Q[current];
		}
		
	}
	printf("%d\n",current+1);
	return current+1;//数组下标和实际顺序相差1  
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int num=0,step=0;
	while(scanf("%d %d",&num,&step)!=EOF)
	{
		choose(num,step);
	}
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