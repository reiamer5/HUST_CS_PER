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

typedef int ElemType;

//#define M 1000
#define N 100

const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1112：拦截导弹
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2552解决：1221
题目描述：
某国为了防御敌国的导弹袭击，开发出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，
但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭，并观测到导弹依次飞来的高度，请计算这套系统最多
能拦截多少导弹。拦截来袭导弹时，必须按来袭导弹袭击的时间顺序，不允许先拦截后面的导弹，再拦截前面的导弹。 
输入：
每组输入有两行，
第一行，输入雷达捕捉到的敌国导弹的数量k（k<=25），
第二行，输入k个正整数，表示k枚导弹的高度，按来袭导弹的袭击时间顺序给出，以空格分隔。
输出：
每组输出只有一行，包含一个整数，表示最多能拦截多少枚导弹。
样例输入：
8
300 207 155 300 299 170 158 65
样例输出：
6
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7835-1-1.htm


*/
int data[N];//导弹的高度数据
int count=0;//导弹数目

//回朔法解决
int trySelect(int current,int last,int selectedNum)
{
	int max1=0;//当前节点被选择达到的最大值
	int max2=0;//不选择当前节点的达到的最大值
	if(current==count-1)//搜索到最后一个节点
	{
		if(data[current]<=data[last])
		{
			selectedNum++;
		}	
		return selectedNum;
	}

	if(data[current]<=data[last])
	{
		max1=trySelect(current+1,current,selectedNum+1);//当前节点被选择达到的最大值	
		max2=trySelect(current+1,last,selectedNum);//不选择当前节点的达到的最大值
		return max1>max2?max1:max2;
	}
	else
	{
		max2=trySelect(current+1,last,selectedNum);//不选择当前节点的达到的最大值
		return max2;
	}
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0,j=0;
	while(scanf("%d",&count)!=EOF)//while 1#
	{
		data[N-1]=MAXINT;
		for(i=0;i<count;i++)
		{
			scanf("%d",data+i);
		}
		printf("%d\n",trySelect(0,N-1,0));
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