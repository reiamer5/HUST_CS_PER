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
#define N 210

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1127：简单密码
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1091解决：637
题目描述：
Julius Caesar曾经使用过一种很简单的密码。
对于明文中的每个字符，将它用它字母表中后5位对应的字符来代替，这样就得到了密文。
比如字符A用F来代替。如下是密文和明文中字符的对应关系。
密文
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
明文
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 
你的任务是对给定的密文进行解密得到明文。
你需要注意的是，密文中出现的字母都是大写字母。密文中也包括非字母的字符，对这些字符不用进行解码。
输入：
输入中的测试数据不超过100组。每组数据都有如下的形式，而且各组测试数据之间没有空白的行。
一组测试数据包括三部分：
1.    起始行 - 一行，包括字符串 "START" 
2.    密文 - 一行，给出密文，密文不为空，而且其中的字符数不超过200
3.    结束行 - 一行，包括字符串 "END" 
在最后一组测试数据之后有一行，包括字符串 "ENDOFINPUT"。
输出：
对每组数据，都有一行输出，给出密文对应的明文。
样例输入：
START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
样例输出：
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
来源：
2008年北京大学方正实验室计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7850-1-1.html

*/
Status explain(char str[N])
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			str[i]=str[i]-5;
			if(str[i]<65)
			{
				str[i]+=26;
			}	
		}
		i++;
	}
	str[i]='\0';
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	char str[N],strF[15];
	gets(strF);
	while(strcmp(strF,"ENDOFINPUT"))//while 1#
	{
		gets(str);
		explain(str);
		gets(strF);
		gets(strF);
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