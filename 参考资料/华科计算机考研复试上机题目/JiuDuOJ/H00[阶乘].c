#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0


typedef int Status;
/*
题目描述：
输入n，
求y1=1!+3!+...m!(m是小于等于n的最大奇数）
y2=2!+4!+...p!(p是小于等于n的最大偶数)。
输入：
每组输入包括1个整数：n
输出：
可能有多组测试数据，对于每组数据，
输出题目要求的y1和y2
样例输入：
4
样例输出：
7 26
*/

/*
n:输入的范围n
oSum:y1=1!+3!+...m!(m是小于等于n的最大奇数
eSum:y2=2!+4!+...p!(p是小于等于n的最大偶数)。
*/

Status factorial(int n,int *oSum,int*eSum)
{
	int y1=0,y2=0;//存放相应的结果
	int i=1;
	int sum=1;//存放累乘结果


	while(i<n-1)
	{
		sum*=i;
		y1+=sum;

		i++;

		sum*=i;
		y2+=sum;

		i++;
	}

	if(n%2==0)//n为偶数 
	{
		sum*=i;
		y1+=sum;

		i++;

		sum*=i;
		y2+=sum;
	}
	else//n为奇数
	{
		sum*=i;
		y1+=sum;
	}

	*oSum=y1;
	*eSum=y2;

	return OK;
}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int oSum=0;
	int eSum=0;

	while(scanf("%d",&n)!=EOF)
	{
		factorial(n,&oSum,&eSum);
		printf("%d %d\n",oSum,eSum);
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