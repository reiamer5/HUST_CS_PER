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

typedef char ElemType;

//#define M 1000
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1111：单词替换
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3580解决：1015
题目描述：
输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。
现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
输入：
多组数据。每组数据输入包括3行，
第1行是包含多个单词的字符串 s，
第2行是待替换的单词a，(长度<=100)
第3行是a将被替换的单词b。(长度<=100)
s, a, b 最前面和最后面都没有空格.
输出：
每个测试数据输出只有 1 行，
将s中所有单词a替换成b之后的字符串。
样例输入：
You want someone to help you
You
I
样例输出：
I want someone to help you
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7834-1-1.html

*/
//用rStr替换str中值为sStr的字符串

Boolean matchChar(char c,char mc)
{
	if(c==mc||c+32==mc||c-32==mc)//c与mc相等 或者仅是大小写不同
	{
		return TRUE;
	}
	return FALSE;
}
Status replaceStr(ElemType str[N],ElemType sStr[N],ElemType rStr[N])
{
	int i=0,j=0,k=0,m=0;
	int count=0;//要替换的处数
	int rIndex[N];//要替换的子串的起始位置
	int lenS=strlen(sStr);
	int lenR=strlen(rStr);
	int len=strlen(str);
	ElemType strTemp[N];
	while(len>i&&str[i]!='\0')
	{	
	
		if(matchChar(str[i],sStr[k])==TRUE)
		{	
			j=i;
			str[5];
			while(len>i&&matchChar(str[i],sStr[k])==TRUE&&str[i]!='\0'&&sStr[k]!='\0'&&(j==0||str[j-1]=='\0'||str[j-1]==' '))
			{
				i++;
				k++;
			}
			
			if(sStr[k]=='\0' && (str[i]=='\0'||str[i]==' ') )
			{
			
				rIndex[count++]=j;//找到一处应被替换的位置
			}
			else
			{
				i=j+1;//回朔
			}	
			k=0;
		}
		else
		{//printf("%c--%c\n",str[i],sStr[k]);
			i++;
		}
	}

	if(count==0)
		return OK;//没有要替换的
	i=0,j=0,k=0,m=0;
	if(lenS==lenR)//被替换的字符串和用来替换的字符串的长度相等
	{
		for(i=0;i<count;i++)
		{
			j=rIndex[i];
			k=0;	
			while(k<lenS)
			{
				str[j]=rStr[k];
				j++;
				k++;
			}
		}
	}
	else if(lenS>lenR)//被替换的字符串大于用来替换的字符串的长度
	{
		j=rIndex[i];
		for(i=0;i<count-1;i++)//for 1#
		{
		
			k=0;
			while(k<lenR)
			{
				str[j]=rStr[k];
				j++;
				k++;
			}
			k=rIndex[i+1]-1;
			m=rIndex[i]+lenS;
			while(m<=k)
			{
				str[j]=str[m];
				j++;
				m++;
			}
		}//end:for 1#

		k=0;
	
		while(k<lenR)
		{	
			str[j]=rStr[k];
			j++;
			k++;
		}
		m=rIndex[i]+lenS;
		while(str[m]!='\0')
		{
			str[j]=str[m];
			j++;
			m++;
		}
	
		str[j]='\0';
	}
	else//被替换的字符串小于用来替换的字符串的长度
	{
		strcpy(strTemp,str);
	//	printf("%s\n",strTemp);
		j=rIndex[i];
		for(i=0;i<count-1;i++)//for 1#
		{
		
			k=0;
			while(k<lenR)
			{
				str[j]=rStr[k];
				j++;
				k++;
			}
			k=rIndex[i+1]-1;
			m=rIndex[i]+lenS;
			while(m<=k)
			{
				str[j]=strTemp[m];
				j++;
				m++;
			}
		}//end:for 1#

		k=0;
		while(k<lenR)
		{
			str[j]=rStr[k];
			j++;
			k++;
		}
		m=rIndex[i]+lenS;
		while(strTemp[m]!='\0')
		{
			str[j]=strTemp[m];
			j++;
			m++;
		}
		str[j]='\0';
	}
	return OK;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	ElemType str[N];
	ElemType sStr[N];
	ElemType rStr[N];	
	while(gets(str)!=NULL)//while 1#
	{
		gets(sStr);
		gets(rStr);
		replaceStr(str,sStr,rStr);
		printf("%s\n",str);
		
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