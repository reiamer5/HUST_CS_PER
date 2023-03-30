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
#define N 100

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1133：学分绩点
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1204解决：630
题目描述：
北京大学对本科生的成绩施行平均学分绩点制（GPA）。既将学生的实际考分根据不同的学科的不同学分按一定的公式进行计算。
公式如下：
实际成绩 绩点
90--100 4.0
85--89 3.7
82--84 3.3
78--81 3.0
75--77 2.7
72--74 2.3
68--71 2.0
64--67 1.5
60--63 1.0
60以下 0
1．一门课程的学分绩点=该课绩点*该课学分
2．总评绩点=所有学科绩点之和/所有课程学分之和
现要求你编写程序求出某人A的总评绩点（GPA）。
输入：
第一行 总的课程数n（n<10）；
第二行 相应课程的学分（两个学分间用空格隔开）；
第三行 对应课程的实际得分；
此处输入的所有数字均为整数。
输出：
输出有一行，总评绩点，精确到小数点后2位小数。（printf("%.2f",GPA);）
样例输入：
5
4 3 4 2 3
91 88 72 69 56
样例输出：
2.52
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7856-1-1.html

*/
double singlePoint(int score)
{
	if(score>=90&&score<=100)
	{
		return 4.0;
	}
	else if(score>=85&&score<=89)
	{
		return 3.7;
	}
	else if(score>=82&&score<=84)
	{
		return 3.3;
	}
	else if(score>=78&&score<=81)
	{
		return 3.0;
	}
	else if(score>=75&&score<=77)
	{
		return 2.7;
	}
	else if(score>=72&&score<=74)
	{
		return 2.3;
	}
	else if(score>=68&&score<=71)
	{
		return 2.0;
	}
	else if(score>=64&&score<=67)
	{
		return 1.5;
	}
	else if(score>=60&&score<=63)
	{
		return 1.0;
	}
	else
		return 0.0;
}

double handleFunction(int data[N][2],int n)
{
	double sum=0.0;
	int total=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		sum=sum+data[i][0]*singlePoint(data[i][1]);
		total=total+data[i][0];
	}
	return sum/total;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	int data[N][2];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i][0]);\
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i][1]);
		}
		printf("%.2lf\n",handleFunction(data,n));
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