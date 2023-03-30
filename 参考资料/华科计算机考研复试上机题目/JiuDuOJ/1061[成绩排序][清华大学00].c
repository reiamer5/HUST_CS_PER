#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define M 102
#define N 1005

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1061：成绩排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：13936解决：3873
题目描述：
    有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名字符的字母序排序，如果姓名的字母序也相同则按照学生的年龄排序，
	并输出N个学生排序后的信息。
输入：
    测试数据有多组，每组输入第一行有一个整数N（N<=1000），接下来的N行包括N个学生的数据。
    每个学生的数据包括姓名（长度不超过100的字符串）、年龄（整形数）、成绩（小于等于100的正数）。
输出：
    将学生信息按成绩进行排序，成绩相同的则按姓名的字母序进行排序。
    然后输出学生信息，按照如下格式：
    姓名 年龄 成绩
样例输入：
3
abc 20 99
bcd 19 97
bed 20 97
样例输出：
bcd 19 97
bed 20 97
abc 20 99
提示：
学生姓名的字母序区分字母的大小写，如A要比a的字母序靠前(因为A的ASC码比a的ASC码要小)。
来源：
2000年清华大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7785-1-1.html
*/

typedef struct Student
{
	char name[M];
	int age;
	int score;
}Student;

Student data[N];
int stuNum;//学生数量

int comp(const void *a,const void *b)
{
	Student *sa=(Student*)a;
	Student *sb=(Student*)b;

	if(sa->score!=sb->score)
	{
		return sa->score-sb->score;
	}	
	else if(strcmp(sa->name,sb->name))
	{
		return strcmp(sa->name,sb->name);	
	}
	return sa->age-sb->age;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	while(scanf("%d",&stuNum)!=EOF)//while 1#
	{
		for(i=0;i<stuNum;i++)
		{
			scanf("%s %d %d",data[i].name,&data[i].age,&data[i].score);
		}
		qsort(data,stuNum,sizeof(Student),comp);
		for(i=0;i<stuNum;i++)
		{
			printf("%s %d %d\n",data[i].name,data[i].age,data[i].score);
		}
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