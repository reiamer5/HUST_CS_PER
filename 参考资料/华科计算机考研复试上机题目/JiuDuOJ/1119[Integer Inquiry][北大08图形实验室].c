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
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1119：Integer Inquiry
时间限制：1 秒内存限制：32 兆特殊判题：否提交：596解决：317
题目描述：
    One of the first users of BIT's new supercomputer was Chip Diller.
    He extended his exploration of powers of 3 to go from 0 to 333 and he explored taking various sums of those numbers. 
    "This supercomputer is great,'' remarked Chip. 
    "I only wish Timothy were here to see these results.''
    (Chip moved to a new apartment, once one became available on the third floor of the Lemon Sky apartments on Third Street.)
输入：
    The input will consist of at most 100 lines of text, each of which contains a single VeryLongInteger. Each VeryLongInteger 
	will be 100 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative).
    The final input line will contain a single zero on a line by itself.
输出：
    Your program should output the sum of the VeryLongIntegers given in the input.
样例输入：
123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0
样例输出：
370370367037037036703703703670
提示：
注意输入数据中，VeryLongInteger 可能有前导0
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7842-1-1.html
*/
Status add(char ad1[N],char ad2[N],char re[N])
{
	int adLen1=strlen(ad1);
	int adLen2=strlen(ad2);

	int c=0;
	int sum=0;

	int i=adLen1-1,j=adLen2-1,k=0;

	while(i>=0&&j>=0)
	{
		sum=ad1[i]+ad2[j]-'0'-'0'+c;
		c=sum/10;
		re[k]=sum%10+'0';
		i--;
		j--;
		k++;
	}
	while(i>=0)
	{
		sum=ad1[i]+-'0'+c;
		c=sum/10;
		re[k]=sum%10+'0';
		i--;
		k++;
	}
	while(j>=0)
	{
		sum=ad2[j]-'0'+c;
		c=sum/10;
		re[k]=sum%10+'0';
		j--;
		k++;
	}
	re[k]='\0';
	i=0;
	k--;
	
	while(i<k)
	{
		c=re[i];
		re[i]=re[k];
		re[k]=c;
		i++;
		k--;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char ad1[N];
	char ad2[N]="0";
	char re[N]="0";

	scanf("%s",ad1);
	while(strcmp(ad1,"0"))//while 1#
	{
		 strcpy(ad2,re);
		 add(ad1,ad2,re);
		 scanf("%s",ad1);
	}//end:while 1#
	printf("%s\n",re);

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