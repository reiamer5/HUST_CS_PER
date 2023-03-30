#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
题目1118：数制转换
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2999解决：1154
题目描述：
    求任意两个不同进制非负整数的转换（2进制～16进制），所给整数在long所能表达的范围之内。
    不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。
输入：
    输入只有一行，包含三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。
	a，b是十进制整数，2 =< a，b <= 16。
    数据可能存在包含前导零的情况。
输出：
    可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，
	即（0，1，...，9，A，B，...，F）。
样例输入：
15 Aab3 7
样例输出：
210306
提示：
可以用字符串表示不同进制的整数。
来源：
2008年北京大学图形实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7841-1-1.html


*/
Status numericalSys(char strOrg[N],char strTo[N],int from,int to)
{
	int i=0,j=0,k=0;
	int strTemp[N];//定义为int 要不然进制太大可能溢出  因为char最大为127
	int strOrgLen=strlen(strOrg);
	int n=0;
	char c;
	//将要被转换的字符串的原始字符串转换为和对应的十进制相等的值存于strTemp中
	while(strOrg[i]!='\0')
	{
		if(isdigit(strOrg[i]))
		{
			strTemp[j]=strOrg[i]-'0';
		}
		else if(isxdigit(strOrg[i]))
		{
			strTemp[j]=toupper(strOrg[i])-'A'+10;
		}
		j++;
		i++;
	}

	strTemp[j]='\0';

	while(n<strOrgLen)
	{
		for(i=n;i<strOrgLen-1;i++)
		{
			if(strTemp[i]%to)
			{
				strTemp[i+1]+=(strTemp[i]%to)*from;	
			}
			strTemp[i]/=to; 
		}
		strTo[k]=strTemp[strOrgLen-1]%to; 
		strTemp[strOrgLen-1]/=to;	
		if(strTo[k]<=9)
		{
			strTo[k]=strTo[k]+'0';
		}
		else
		{
			strTo[k]=strTo[k]+'A'-10;
		}
		k++;
		if(strTemp[n]==0)
		{
			n++;
		}	
	}
	//求得的结果与实际顺序刚好相反
	i=0;
	strTo[k]='\0';
	k--;

	//处理前导零
	while(strTo[k]=='0'&&k>0)
	{
		strTo[k]=strTo[k+1];
		k--;
	}

	while(i<k)//作转置
	{
		c=strTo[i];
		strTo[i]=strTo[k];
		strTo[k]=c;
		i++;
		k--;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char strOrg[N];
	char strTo[N];
	int from;
	int to;

	while(scanf("%d %s %d",&from,strOrg,&to)!=EOF)//while 1#
	{
		numericalSys(strOrg,strTo,from,to);
		printf("%s\n",strTo);
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