#include<stdio.h>
#include<string.h>
//定义状态码
#define OK 1
#define ERROR 0

typedef int Status;
typedef int Boolean;

#define N 1000

/*************************题目说明********************/
/*
题目1138：进制转换
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1808解决：724
题目描述：
将一个长度最多为30位数字的十进制非负整数转换为二进制数输出。
输入：
多组数据，每行为一个长度不超过30位的十进制非负整数。
（注意是10进制数字的个数可能有30个，而非30bits的整数）
输出：
每行输出对应的二进制数。
样例输入：
0
1
3
8
样例输出：
0
1
11
1000
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7861-1-1.html
*/

//将十进制字符串dStr转换成二进制字符串tStr
Status dTob(char dStr[N],char tStr[N])
{
	int i=0;
	int len=strlen(dStr);
	int n=0;
	int k=0;
	char strTemp[N];
	char c;
	for(i=0;i<len;i++)
	{
		strTemp[i]=dStr[i]-'0';//将字符串中的每个字符的值转换为其十进制中对应的值
	}
	n=0;
	while(n<len)
	{
		for(i=n;i<len-1;i++)
		{
			if(strTemp[i]%2==1)
			{
				strTemp[i+1]+=10;//高位模2余1 相当于次高位余10	
			}			
			strTemp[i]/=2;
		}
		tStr[k++]=strTemp[len-1]%2+'0';
		strTemp[len-1]/=2;
		if(strTemp[n]==0)
		{
			n++;
		}	
	}

	//求得的结果与实际顺序刚好相反
	i=0;
	tStr[k]='\0';
	k--;
	while(i<k)//作转置
	{
		c=tStr[i];
		tStr[i]=tStr[k];
		tStr[k]=c;
		i++;
		k--;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	char dStr[N];
	char tStr[N];
	while(scanf("%s",dStr)!=EOF)//while 1#
	{
		 dTob(dStr,tStr);
		 printf("%s\n",tStr);
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