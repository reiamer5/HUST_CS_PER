#include<stdio.h>
//#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 1000
/*
题目描述：
给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。
输入：
输入有多组，每组包含n（n<=600）和n个不同的整数，整数大于1且小于等于1000。
当n=0时，程序结束，不需要处理这组数据。
输出：
每行输出最简真分数组合的个数。
样例输入：
7
3 5 7 9 11 13 15
3 
2 4 5
0
样例输出：
17 
2

*/
//辗转相除法求最大公约数
int gcd(int a,int b)
{
	int temp,x=a,y=b;
	if(a<b)
	{
		x=b;
		y=a;
	}
	while(x%y!=0)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return y;
}
int search(int data[N],int n)
{
	int sum=0;
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j!=i&&data[i]&&data[j])
			{
				if((data[i]==1 ||data[i]==-1 )||(data[i]<data[j]&&gcd(data[j],data[i])==1))
				{
					sum++;
				}
			}
		}
	}

	return sum;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int data[N];
	int n=0;
	int i=0;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",data+i);
		}
		printf("%d\n",search(data,n));	
		scanf("%d",&n);
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