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
#define N 200

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1177：查找
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5786解决：1709
题目描述：
    读入一组字符串（待操作的），再读入一个int n记录记下来有几条命令，总共有2中命令：
	1、翻转  从下标为i的字符开始到i+len-1之间的字符串倒序；
	2、替换  命中如果第一位为1，用命令的第四位开始到最后的字符串替换原读入的字符串下标 i 到 i+len-1的字符串。
	   每次执行一条命令后新的字符串代替旧的字符串（即下一条命令在作用在得到的新字符串上）。
    命令格式：第一位0代表翻转，1代表替换；第二位代表待操作的字符串的起始下标int i；第三位表示需要操作的字符串长度int len。
输入：
输入有多组数据。
每组输入一个字符串（不大于100）然后输入n，再输入n条指令（指令一定有效）。
输出：
根据指令对字符串操作后输出结果。
样例输入：
bac
2
003
112as
样例输出：
cab
cas
来源：
2011年北京邮电大学网院研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7900-1-1.html
abcdefg
4
002
12544444
025

*/
Status handleFunction(char str[N],char command[N])
{
	int startIndex,endIndex;
	int i,mid,j;
	char c;	
	int length=strlen(str);

	if(command[0]=='0')//1、翻转 
	{
		startIndex=command[1]-'0';
		endIndex=startIndex+command[2]-'0'-1;
		//printf("%d %d\n",startIndex,endIndex);
		mid=(startIndex+endIndex)/2;//求取翻转的中间位置
		while(startIndex<endIndex)
		{
			c=str[startIndex];
			str[startIndex]=str[endIndex];
			str[endIndex]=c;
			startIndex++;
			endIndex--;
		}
		printf("%s\n",str);		
	}
	else//2、替换 
	{	
		startIndex=command[1]-'0';
		endIndex=startIndex+command[2]-'0'-1;
		i=startIndex;
		j=3;
	//	printf("%d %d\n",startIndex,endIndex);
		while(i<=endIndex)
		{
			str[i]=command[j];
			i++;
			j++;
		}
		if(i>length)
		{
			str[i]='\0';
		}
		printf("%s\n",str);		
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;
	char str[N];
	char command[N];
	while(scanf("%s",str)!=EOF)//while 1#
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",command);
			handleFunction(str,command);
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