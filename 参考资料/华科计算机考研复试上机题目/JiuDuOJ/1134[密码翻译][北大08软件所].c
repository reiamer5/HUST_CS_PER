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

#define N 100

/*************************题目说明********************/
/*
题目1134：密码翻译
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1809解决：732
题目描述：
    在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，
	但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y,A-Y的字母用其后继字母替代，
	把z和Z用a和A替代，则可得到一个简单的加密字符串。
输入：
        可能有多组测试数据。每组测试数据的第一行是字符串的数目n， (也要使用get(s)读取字符串,再用n=atoi(s)获得整数数值)，
		其余n行每行一个字符串,用gets(s)方式读取这一行字符串.每个字符串长度小于80个字符。
输出：
    对于每组数据，输出每行字符串的加密字符串。
样例输入：
1
Hello! How are you!
样例输出：
Ifmmp! Ipx bsf zpv!
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7857-1-1.html
*/
Status handleFunction(ElemType str[N])
{
	int i=0;
	while(str[i]!='\0')
	{
		if((str[i]>='a'&&str[i]<='y')||(str[i]>='A'&&str[i]<='Y'))
		{
			str[i]=str[i]+1;
		}
		else if(str[i]=='z')
		{
			str[i]='a';
		}
		else if(str[i]=='Z')
		{
			str[i]='A';
		}
		i++;
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	char str[N];

	while(gets(str)!=NULL)//while 1#
	{
		n=atoi(str);
		//printf("%d\n",n);
		for(i=0;i<n;i++)
		{
			gets(str);
			handleFunction(str);
			printf("%s\n",str);
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