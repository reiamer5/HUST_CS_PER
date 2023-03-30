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
题目1196：成绩排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3806解决：1263
题目描述：
用一维数组存储学号和成绩，然后，按成绩排序输出。
输入：
输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。
接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
输出：
按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
如果学生的成绩相同，则按照学号的大小进行从小到大排序。
样例输入：
3
1 90
2 87
3 92
样例输出：
2 87
1 90
3 92
*/

typedef struct Stu
{
	int id;
	int score;
}Stu;

Status sort(Stu stu[N],int n)
{
	int i=0,j=0;
	Boolean finished=FALSE;
	Stu temp;

	for(i=0;i<n&&finished==FALSE;i++)
	{
		finished=TRUE;
		for(j=0;j<n-i-1;j++)
		{
			if(stu[j].score>stu[j+1].score)
			{
				finished=FALSE;
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;

			}
			else if(stu[j].score==stu[j+1].score&&stu[j].id>stu[j+1].id)
			{
				finished=FALSE;
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	int n=0;
	Stu stu[N];
	int i=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&stu[i].id,&stu[i].score);
		}
		sort(stu,n);
		for(i=0;i<n;i++)
		{
			printf("%d %d\n",stu[i].id,stu[i].score);
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