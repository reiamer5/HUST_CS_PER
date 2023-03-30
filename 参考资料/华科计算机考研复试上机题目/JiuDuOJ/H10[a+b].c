#include<stdio.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Boolean;
#define N 2000
/*
题目1198：a+b
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5199解决：1805
题目描述：
实现一个加法器，使其能够输出a+b的值。
输入：
输入包括两个数a和b，其中a和b的位数不超过1000位。
输出：
可能有多组测试数据，对于每组数据，
输出a+b的值。
样例输入：
2 6
10000000000000000000 10000000000000000000000000000000
样例输出：
8
10000000000010000000000000000000

*/

Status add(char strA[N],char strB[N],char strC[N])
{
	int lenghA=strlen(strA)-1;
	int lenghB=strlen(strB)-1;
	int i=0;
	int c=0;//进位
	int sum=0;//每一位相加的和
	int low,high;
	char temp;
	
	while(lenghA>=0&&lenghB>=0)//按位相加
	{
		sum=strA[lenghA]+strB[lenghB]-'0'-'0'+c;
		c=sum/10;
		strC[i]=sum%10+'0';
		lenghA--;
		lenghB--;
		i++;
	}
//处理较长的字符串余下的字符
	while(lenghA>=0)
	{
		sum=strA[lenghA]-'0'+c;
		c=sum/10;
		strC[i]=sum%10+'0';
		lenghA--;
		i++;
	}
	while(lenghB>=0)
	{
		sum=strB[lenghB]-'0'+c;
		c=sum/10;
		strC[i]=sum%10+'0';
		lenghB--;
		i++;
	}
	while(c>0)//易错 想想5+8各位数相加就知道了
	{
		strC[i]=c%10+'0';
		i++;
		c/=10;
	}
	strC[i]='\0';
	low=0;
	high=i-1;
	while(low<high)//将strC转置
	{
		temp=strC[low];
		strC[low]=strC[high];
		strC[high]=temp;
		low++;
		high--;
	}

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

	char strA[N],strB[N],strC[N];
	while(scanf("%s %s",strA,strB)!=EOF)
	{
		add(strA,strB,strC);
		printf("%s\n",strC);
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