#include<stdio.h>
#include<string.h>
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
#define N 20

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
时间限制：1 秒内存限制：32 兆特殊判题：否提交：543解决：223
题目描述：
    Children are taught to add multi-digit numbers from right-to-left one digit at a time. 
	Many find the "carry" operation - in which a 1 is carried from one digit position to be 
	added to the next - to be a significant challenge. Your job is to count the number of carry 
	operations for each of a set of addition problems so that educators may assess their difficulty. 
输入：
    Each line of input contains two unsigned integers less than 10 digits. The last line of input contains 0 0.
输出：
    For each line of input except the last you should compute and print the number of carry operations that 
	would result from adding the two numbers, in the format shown below.
样例输入：
123 456
555 555
123 594
0 0
样例输出：
NO carry operation.
3 carry operations.
1 carry operation.
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7866-1-1.html


*/
Status handleFunction(char ad1[N],char ad2[N])
{
	int sum=0;
	int c=0;
	int adLen1=strlen(ad1)-1;
	int adLen2=strlen(ad2)-1;

	int count =0;

	while(adLen1>=0&&adLen2>=0)
	{
		sum=ad1[adLen1]+ad2[adLen2]-'0'-'0'+c;
		c=sum/10;
		sum/=10;
		count+=c; 
		adLen1--;
		adLen2--;
	}
	
	while(adLen1>=0)
	{
		sum=ad1[adLen1]-'0'+c;
		c=sum/10;
		sum/=10;
		count+=c;
		adLen1--;
	}
	
	while(adLen2>=0)
	{
		sum=ad2[adLen2]-'0'+c;
		c=sum/10;
		sum/=10;
		count+=c;
		adLen2--;
	}
	

	if(count==0)
	{
		printf("NO carry operation.\n");
	}
	else if(count==1)
	{
		printf("1 carry operation.\n");
	}
	else
	{
		printf("%d carry operations.\n",count);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char ad1[N],ad2[N];

	scanf("%s %s",ad1,ad2);
	while(strcmp(ad1,"0")||strcmp(ad2,"0"))//while 1#
	{
		handleFunction(ad1,ad2);
		scanf("%s %s",ad1,ad2);
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