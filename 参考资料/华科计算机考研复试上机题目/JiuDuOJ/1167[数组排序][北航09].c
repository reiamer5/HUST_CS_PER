#include<stdio.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

typedef int ElemType;

#define N 10005

/*************************题目说明********************/
/*
题目1167：数组排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：4625解决：1483
题目描述：
输入一个数组的值,求出各个值从小到大排序后的次序。
输入：
输入有多组数据。
每组输入的第一个数为数组的长度n(1<=n<=10000),后面的数为数组中的值,以空格分割。
输出：
各输入的值按从小到大排列的次序(最后一个数字后面没有空格)。
样例输入：
4
-3 75 12 -3
样例输出：
1 3 2 1
来源：
2009年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7890-1-1.html
*/	

ElemType data1[N];
ElemType data2[N][2];
int n;
Status handleFunction()
{
	int i=0,j=0;
	int count=1;
	int temp=0;
	Boolean flag=TRUE; 
	for(i=0;i<n&&flag==TRUE;i++)
	{
		flag=FALSE;
		for(j=0;j<n-i-1;j++)
		{
			if(data2[j][0]>data2[j+1][0])
			{
				temp=data2[j][0];
				data2[j][0]=data2[j+1][0];
				data2[j+1][0]=temp;
				flag=TRUE;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{	
		if(data2[i][0]==data2[i+1][0])
		{
			while(data2[i][0]==data2[i+1][0])
			{
				data2[i][1]=count;
				i++;
			}
		}
		data2[i][1]=count;
		count++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(data1[i]==data2[j][0])
			{
				printf("%d ",data2[j][1]);
				break;
			}
		}
	
	}

	for(j=0;j<n;j++)
	{
		if(data1[i]==data2[j][0])
		{
			printf("%d\n",data2[j][1]);
			break;
		}
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;

	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data1+i);
			data2[i][0]=data1[i];
		}
		handleFunction();
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