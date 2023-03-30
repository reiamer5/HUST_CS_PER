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
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1153：括号匹配问题
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3689解决：1647
题目描述：
    在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）
	任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，
	输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
输入：
    输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100。
    注意：cin.getline(str,100)最多只能输入99个字符！
输出：
    对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
样例输入：
)(rttyy())sss)(
样例输出：
)(rttyy())sss)(
?            ?$
来源：
2010年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7876-1-1.html

*/

Status handleFunction(char str[N])
{
	int left[N];
	int right[N];
	int lsize=0;
	int rsize=0;
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='(')
		{			
			left[lsize]=i;
			lsize++;
		}
		else if(str[i]==')')
		{
			if(lsize>0)
			{
				lsize--;
			}
			else
			{
				right[rsize]=i;
				rsize++;
			}
		}
		i++;
	}

	i=0;
	while(str[i]!='\0')
	{
		str[i]=' ';
		i++;
	}
	lsize--;
	while(lsize>=0)
	{
		str[left[lsize]]='$';
		lsize--;
	}
	rsize--;
	while(rsize>=0)
	{
		str[right[rsize]]='?';
		rsize--;
	}
	printf("%s\n",str);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str[N];

	while(gets(str)!=NULL)//while 1#
	{
		printf("%s\n",str);
		handleFunction(str);
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