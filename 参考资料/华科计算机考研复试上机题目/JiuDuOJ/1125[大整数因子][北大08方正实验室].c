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

#define N 40

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1125：大整数的因子
时间限制：1 秒内存限制：32 兆特殊判题：否提交：866解决：428
题目描述：
已知正整数k满足2<=k<=9，现给出长度最大为30位的十进制非负整数c，求所有能整除c的k.
输入：
若干个非负整数c，c的位数<=30
每行一个c，当c=-1时中止
（不要对-1进行计算！）
输出：
每一个c的结果占一行
1) 若存在满足 c%k == 0 的k，输出所有这样的k，中间用空格隔开，最后一个k后面没有空格。
2) 若没有这样的k则输出"none"
样例输入：
30
72
13
-1
样例输出：
2 3 5 6
2 3 4 6 8 9
none
提示：
注意整数溢出问题
不要对-1进行计算
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7848-1-1.html
*/
Status handleFunction(char str[N])
{	int divi[8];//存放因子
	int size=0;//因子的个数
	
	int sum=0;
	int i=0,k=0,w=0;
	int strLen=strlen(str);
	
	k=2;
	while(k<=9)
	{
		sum=0;
		w=0;//清零
		for(i=0;i<strLen;i++)
		{
			sum=str[i]-'0'+w*10;
			w=sum%k;
		}
		if(sum%k==0)
		{
			divi[size++]=k;
		}
		k++;
	}

	if(size==0)
	{
		printf("none\n");
		return OK;
	}
	for(i=0;i<size-1;i++)
	{
		printf("%d ",divi[i]);
	}
	printf("%d\n",divi[i]);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];
	scanf("%s",str);
	while(strcmp(str,"-1"))//while 1#
	{
		handleFunction(str);
		scanf("%s",str);
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