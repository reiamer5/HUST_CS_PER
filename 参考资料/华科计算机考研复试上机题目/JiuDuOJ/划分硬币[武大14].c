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
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*


*/
int judge(int money,int value)
{
	int total=0;
	int i=0;
	int limit=0;
	if(money==0||value==1)
	{
		return 1;
	}

	limit=money/value;
	if(value==5)
	{
		while(i<=limit)
		{
			total+=judge(money-i*5,2);
			i++;
		}

	}
	else if(value==2)
	{
		while(i<=limit)
		{
			total+=judge(money-i*2,1);
			i++;
		}
	}
	
	return total;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		printf("%d\n",judge(n,5));
		scanf("%d",&n);
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