#include<stdio.h>
#include<malloc.h>
//#include<stdlib.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

//判断是否是守型数
Boolean judge(int number)
{

	int num=number*number;
	if((num%10==number||num%100==number||num%1000==number)&&number>1&&number<100)
		return TRUE;
	return FALSE;

}


//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int number=0;
	while(scanf("%d",&number)!=EOF)
	{
		if(TRUE==judge(number))
		{
			printf("Yes!\n");
		}
		else
		{
			printf("No!\n");
		}
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