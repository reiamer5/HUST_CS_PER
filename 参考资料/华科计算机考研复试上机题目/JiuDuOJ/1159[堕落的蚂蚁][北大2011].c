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
#define N 512

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
目1159：坠落的蚂蚁
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1004解决：246
题目描述：
    一根长度为1米的木棒上有若干只蚂蚁在爬动。它们的速度为每秒一厘米或静止不动，方向只有两种，向左或者向右。
	如果两只蚂蚁碰头，则它们立即交换速度并继续爬动。三只蚂蚁碰头，则两边的蚂蚁交换速度，中间的蚂蚁仍然静止。
	如果它们爬到了木棒的边缘（0或100厘米处）则会从木棒上坠落下去。在某一时刻蚂蚁的位置各不相同且均在整数厘米处
	（即1，2，3，…99厘米），有且只有一只蚂蚁A速度为0，其他蚂蚁均在向左或向右爬动。给出该时刻木棒上的所有蚂蚁位
	置和初始速度，找出蚂蚁A从此时刻到坠落所需要的时间。
输入：
    第一行包含一个整数表示蚂蚁的个数N（2<=N<=99），之后共有N行，每一行描述一只蚂蚁的初始状态。每个初始状态由两个整数组成，
	中间用空格隔开，第一个数字表示初始位置厘米数P（1<=P<=99），第二个数字表示初始方向,-1表示向左，1表示向右，0表示静止。
输出：
    蚂蚁A从开始到坠落的时间。若不会坠落，输出"Cannot fall!"
样例输入：
4
10 1
90 0
95 -1
98 -1
样例输出：
98
来源：
2011年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7882-1-1.html


*/
Status handleFunction(int data[N],int n)
{
	int zeroPos=0;
	int left[N];
	int right[N];
	int i=0,j=0,k1=0,k2=0;

	memset(left,-1,N);
	memset(right,-1,N);

	for(i=1;i<=100;i++)//寻找静止的蚂蚁位置
	{
		if(data[i]==0)
		{
			//printf("%d",i);
			zeroPos=i;		
			break;
		}
	}
	j=zeroPos+1;
	k1=1;
	while(j<=100)
	{
		if(data[j]==-1)
		{	//-1表示向左，1表示向右
			right[k1++]=j;
		}
		j++;
	}

	j=zeroPos-1;
	k2=1;
	while(j>=1)
	{
		if(data[j]==1)
		{	//-1表示向左，1表示向右
			left[k2++]=j;
		}
		j--;
	
	}
	if(k1==k2)
	{
		printf("Cannot fall!\n");
		return OK;
	}
	if(k1>k2)//右边多
	{
		printf("%d\n",right[k2]);
	}
	else
	{
		printf("%d\n",100-left[k1]);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,status=0,j=0;
	int data[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		memset(data,3,N);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&j,&status);
			data[j]=status;
		}
		handleFunction(data,n);
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