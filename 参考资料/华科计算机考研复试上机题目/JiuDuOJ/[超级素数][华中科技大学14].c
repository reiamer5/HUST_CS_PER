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

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
*/

Boolean isPrime(int x)
{
	int i=0;
	int limit=(int)sqrt(x);

	if(x<=1)
		return FALSE;

	for(i=2;i<=limit;i++)
	{
		if(x%i==0)
			return FALSE;
	}
	return TRUE;
}
Status handleFunction()
{
	int k=1000;
	int count=0;

	for(k=1000;k<=9999;k++)
	{
		if(TRUE==isPrime(k/1000)&&TRUE==isPrime(k/100)&&TRUE==isPrime(k/10)&&TRUE==isPrime(k))
		{
			count++;
			if(count<=5)
			{
				printf("%d ",k);
			}
			else
			{
				printf("%d\n",k);
				count=0;
			}
			
		}
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	handleFunction();
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