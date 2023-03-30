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

#define N 100

Status task0()
{
	printf("task0 is called!\n");
	return OK;
}

Status task1()
{
	printf("task1 is called!\n");
	return OK;
}

Status task2()
{
	printf("task2 is called!\n");
	return OK;
}

Status task3()
{
	printf("task3 is called!\n");
	return OK;
}

Status task4()
{
	printf("task4 is called!\n");
	return OK;
}

Status task5()
{
	printf("task5 is called!\n");
	return OK;
}

Status task6()
{
	printf("task6 is called!\n");
	return OK;
}

Status task7()
{
	printf("task7 is called!\n");
	return OK;
}

Status task8()
{
	printf("task8 is called!\n");
	return OK;
}


Status schedule(char cmd[N])
{
	char *p=cmd;
	Status (*fp[9])();
	fp[0]=task0;
	fp[1]=task1;
	fp[2]=task2;
	fp[3]=task3;
	fp[4]=task4;
	fp[5]=task5;
	fp[6]=task6;
	fp[7]=task7;
	fp[8]=task8;

	while(*p!='\0')
	{
		(*fp[*p-'0'])();
		p++;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	while(scanf("%s",str)!=EOF)//while 1#
	{
		schedule(str);
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