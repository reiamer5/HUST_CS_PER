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
#define N 1200

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1477：怪异的洗牌
时间限制：1 秒内存限制：128 兆特殊判题：否提交：540解决：200
题目描述：
        对于一副扑克牌，我们有多种不同的洗牌方式。一种方法是从中间某个位置分成两半，然后相交换，我们称之为移位（shift）。
		比如原来的次序是123456，从第4个位置交换，结果就是561234。这个方式其实就是数组的循环移位，为了多次进行这个操作，
		必须使用一种尽可能快的方法来编程实现。在本题目中，还引入另外一种洗牌方式，就是把前一半（如果总数是奇数，就是(n-1)/2）牌翻转过来，
		这种操作称之为翻转（flip）。在前面shift操作的结果上进行flip，结果就是165234。当然，如果是实际的扑克牌，直接翻转会造成正反面混在一起的，我们就不管那么多了。
        给定n张牌，初始次序为从1到n，经过若干次的shift和flip操作后，结果会是什么样？
输入：
输入包括多组测试数据，每组数据的第一行包括两个数 n和k。n表示牌的数目，1<n<1000，如果n为0表示输入结束，k表示下面要进行的操作数量。随后的k行，每行一个整数x，1<=x<=n，表示从第几个位置开始移位。在每一次shift操作后都接一个flip操作。
输出：
对于输入的每组数据，计算经过给定的k次shift和flip操作后，各个位置的数值。并按次序在一行上输出所有牌张的值，每个数值（包括最后一个）后面有一个空格。
样例输入：
6 1
4
0 0
样例输出：
1 6 5 2 3 4
*/

Status reversal(int data[N],int begin,int end)
{
	int temp=0;
	while(begin<end)
	{
		temp=data[begin];
		data[begin]=data[end];
		data[end]=temp;
		begin++;
		end--;
	}
	return OK;
}
Status shift(int data[N],int num,int start)
{
	reversal(data,0,num-1);
	reversal(data,0,num-start-1);
	reversal(data,num-start,num-1);
	return OK;
}

Status flip(int data[N],int num)
{
	if(num%2==0)
	{
		reversal(data,0,(num-1)/2);
	}
	else
	{
		reversal(data,0,num/2-1);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0,k=0;
	int i=0;
	int x=0;
	int data[N];
	scanf("%d %d",&n,&k);
	while(n)//while 1#
	{
		for(i=0;i<n;i++)
		{
			data[i]=i+1;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			shift(data,n,x);
			flip(data,n);
		
		}	
		for(i=0;i<n;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		scanf("%d %d",&n,&k); 
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