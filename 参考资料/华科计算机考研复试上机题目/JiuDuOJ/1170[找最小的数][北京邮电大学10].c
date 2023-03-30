#include<stdio.h>
//#include<string.h>
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
#define N 1100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1170：找最小数
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5387解决：2383
题目描述：
第一行输入一个数n，1 <= n <= 1000，下面输入n行数据，每一行有两个数，分别是x y。输出一组x y，该组数据是所有数据中x最小，
且在x相等的情况下y最小的。 
输入：
输入有多组数据。
每组输入n，然后输入n个整数对。
输出：
输出最小的整数对。
样例输入：
5  
3 3  
2 2  
5 5  
2 1  
3 6
样例输出：
2 1
来源：
2010年北京邮电大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7893-1-1.html

*/

int data[N][2];
Status searchMin(int n)
{
	int i=0;
	int j=0;
	int temp=0;
	Boolean flag=TRUE;
	for(i=0;i<n&&TRUE==flag;i++)//采用冒泡排序
	{
		flag=FALSE;
		for(j=0;j<n-i-1;j++)
		{
			//比较：输出一组x y，该组数据是所有数据中x最小，且在x相等的情况下y最小的。 
			if(data[j][0]>data[j+1][0] || ((data[j][0]==data[j+1][0])&&(data[j][1]>data[j+1][1])))
			{	//交换元素
				temp=data[j][0];
				data[j][0]=data[j+1][0];
				data[j+1][0]=temp;

				temp=data[j][1];
				data[j][1]=data[j+1][1];
				data[j+1][1]=temp;
				//设置标志
				flag=TRUE;
			}
		}
	}
	printf("%d %d\n",data[0][0],data[0][1]);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",*(data+i),*(data+i)+1);
		}

		searchMin(n);
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