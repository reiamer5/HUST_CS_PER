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

#define M 32
#define N 128

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1066：字符串排序
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5086解决：2064
题目描述：
 输入一个长度不超过20的字符串，对所输入的字符串，按照ASCII码的大小从小到大进行排序，请输出排序后的结果
输入：
 一个字符串，其长度n<=20
输出：
 输入样例可能有多组，对于每组测试样例，
按照ASCII码的大小对输入的字符串从小到大进行排序，输出排序后的结果
样例输入：
dcba
样例输出：
abcd
来源：
2001年清华大学计算机研究生机试真题(第II套)
*/

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int data[N];
	char str[M];
	int i=0;

	while(gets(str)!=NULL)//while 1#
	{
		memset(data,0,N*sizeof(int));
		i=0;
		while(str[i]!='\0')
		{
			data[str[i]]++;
			i++;
		}
		for(i=0;i<N;i++)
		{	
			while(data[i]>0)
			{
				printf("%c",i);
				data[i]--;
			}	
		}
		printf("\n");
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