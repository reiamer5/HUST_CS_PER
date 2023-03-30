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

typedef int ElemType;

#define M 1000
#define N 50

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1165：字符串匹配
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2821解决：973
题目描述：
    读入数据string[ ]，然后读入一个短字符串。要求查找string[ ]中和短字符串的所有匹配，输出行号、匹配字符串。匹配时不区分大小写，并且可以有一个用中括号表示的模式匹配。如"aa[123]bb"，就是说aa1bb、aa2bb、aa3bb都算匹配。
输入：
输入有多组数据。
每组数据第一行输入n(1<=n<=1000)，从第二行开始输入n个字符串（不含空格），接下来输入一个匹配字符串。
输出：
输出匹配到的字符串的行号和该字符串（匹配时不区分大小写）。
样例输入：
4
Aab
a2B
ab
ABB
a[a2b]b
样例输出：
1 Aab
2 a2B
4 ABB
来源：
2008年北京航空航天大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7888-1-1.html
*/


//字符匹配:如果匹配成功返回TRUE 否则返回FALSE
Boolean matchChar(char c,char mc)
{
	if(c==mc||c+32==mc||c-32==mc)//c与mc相等 或者仅是大小写不同
	{
		return TRUE;
	}
	return FALSE;
}

//字符串匹配:如果匹配成功返回TRUE 否则返回FALSE
Boolean matchStr(char *str,char *model)
{
	int i=0,j=0;
	while(*str!='\0'&&*model!='\0')
	{
		if(TRUE==matchChar(*str,*model))
		{
			str++;
			model++;
		}
		else if(*model=='[')
		{
			model++;
			while(*model!=']')
			{
				if(matchChar(*str,*model)==TRUE)
				{
					str++;
					while(*model!=']')
					{
						model++;
					}
				}
				else if(*model!=']')
				{
					model++;
				}
			}
			model++;
		}
		else
			return FALSE;
	}

	if(*str=='\0'&&*model=='\0')
		return TRUE;
	return FALSE;
}
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	char str[M][N];
	char model[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		scanf("%s",model);
		for(i=0;i<n;i++)
		{
			if(matchStr(str[i],model)==TRUE)
				printf("%d %s\n",i+1,str[i]);
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