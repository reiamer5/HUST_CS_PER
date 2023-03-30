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

#define M 128
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1150：Counterfeit Dollar
时间限制：1 秒内存限制：32 兆特殊判题：否提交：435解决：191
题目描述：
    Sally Jones has a dozen Voyageur silver dollars. However, only eleven of the coins are true silver dollars; one coin is 
	counterfeit even though its color and size make it indistinguishable from the real silver dollars. The counterfeit coin 
	has a different weight from the other coins but Sally does not know if it is heavier or lighter than the real coins. 
    Happily, Sally has a friend who loans her a very accurate balance scale. The friend will permit Sally three weighings
	to find the counterfeit coin. For instance, if Sally weighs two coins against each other and the scales balance then 
	she knows these two coins are true. Now if Sally weighs one of the true coins against a third coin and the scales do 
	not balance then Sally knows the third coin is counterfeit and she can tell whether it is light or heavy depending on
	whether the balance on which it is placed goes up or down, respectively. 
    By choosing her weighings carefully, Sally is able to ensure that she will find the counterfeit coin with exactly three weighings.
输入：
    For each case, the first line of input is an integer n (n > 0) specifying the number of cases to follow. 
	Each case consists of three lines of input, one for each weighing. Sally has identified each of the coins
	with the letters A--L. Information on a weighing will be given by two strings of letters and then one of 
	the words ``up'', ``down'', or ``even''. The first string of letters will represent the coins on the left
	balance; the second string, the coins on the right balance. (Sally will always place the same number of 
	coins on the right balance as on the left balance.) The word in the third position will tell whether the 
	right side of the balance goes up, down, or remains even.
输出：
    For each case, the output will identify the counterfeit coin by its letter and tell whether it is heavy
	or light. The solution will always be uniquely determined.
样例输入：
3
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 

ABCD EFGH even 
ABCI EFJK down 
ABIJ EFGH even 

ABCD EFGH even 
EFJK ABCI up 
ABIJ EFGH even 
样例输出：
K is the counterfeit coin and it is light.
来源：
2010年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7873-1-1.html


*/

int exist[M];
Status add(char *str)
{
	while(*str!='\0')
	{
		exist[*str]++;
		str++;
	}	
	return OK;
}

Status judge(char *str1,char *str2,char *tagStr)
{
	while(*str1!='\0')
	{
		if(exist[*str1]==0)
		{
			if(strcmp(tagStr,"up")==0)
			{
				printf("%c is the counterfeit coin and it is heavy.\n",*str1);
			}
			else
			{
				printf("%c is the counterfeit coin and it is light.\n",*str1);
			}
			return OK;
		}
		str1++;
	}
	
	while(*str2!='\0')
	{
		if(exist[*str2]==0)
		{
			if(strcmp(tagStr,"up")==0)
			{
				printf("%c is the counterfeit coin and it is light.\n",*str2);
			}
			else
			{
				printf("%c is the counterfeit coin and it is heavy.\n",*str2);
			}
			return OK;
		}
		str2++;
	}	
	return OK;
}




//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	char str1[N],str2[N],str3[10];
	char judgeStr1[N],judgeStr2[N],tagStr[10];
	scanf("%d",&n);
	while(n>0)//while 1#
	{
		for(i=0;i<M;i++)
		{
			exist[i]=0;//初始化标志数组
		}
		for(i=0;i<3;i++)
		{
			scanf("%s %s %s",str1,str2,str3);
			if(strcmp(str3,"even")==0)
			{
				add(str1);
				add(str2);
			}
			else
			{
				strcpy(judgeStr1,str1);
				strcpy(judgeStr2,str2);
				strcpy(tagStr,str3);
			}
		}
		judge(judgeStr1,judgeStr2,tagStr);
		n--;
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