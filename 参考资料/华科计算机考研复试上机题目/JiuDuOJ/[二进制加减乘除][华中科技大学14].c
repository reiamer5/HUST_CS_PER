#include<stdio.h>
#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

#define N 256

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*


*/
//将二进制字符串转换为十进制无符号数
int bstrTodi(char *bstr)
{
	int strLen=strlen(bstr);
	int sum=0;
	int shift=1;
	int i=strLen-1;
	while(i>=0)
	{
		sum+=(*(bstr+i)-'0')*shift;
		shift=shift<<1;
		i--;
	}

	return sum;
}
//将十进制数转换为二进制字符串
Status diTobStr(int num,char str[N])
{	
	int i=0;
	int high=0,low=0;
	int fnum=(int)fabs(num);
	while(fnum>0)//将十进制数转换为二进制字符串
	{
		str[i++]=fnum%2+'0';
		fnum=fnum>>1;
	}
	if(num<0)
	{
		str[i++]='-';
	}
	str[i]='\0';
	high=i-1;
	//将字符串转置
	while(low<high)
	{
		i=str[low];
		str[low]=str[high];
		str[high]=i;
		low++;
		high--;
	}

	return OK;
}
Status handleFunction(char *opStr1,char *opStr2,char c)
{
	int op1=bstrTodi(opStr1);
	int op2=bstrTodi(opStr2);
	char reStr[N];
	int re=0;
	switch(c)
	{
		case '+':
			re=op1+op2;
			diTobStr(re,reStr);
			break;
		case '-':
			re=op1-op2;
			diTobStr(re,reStr);
			break;
		case '*':
			re=op1*op2;
			//printf("%d ",re);
			diTobStr(re,reStr);
			break;
		case '/':
			if(op2==0)
			{
				printf("parameter is illegal!\n");
				return ERROR;
			}
			re=(int)op1/op2;
			diTobStr(re,reStr);
			break;
		default:return OK;
	}
	printf("=%s\n",reStr);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	char str1[N],str2[N],op[5];
	while(scanf("%s %s %s",str1,str2,op)!=EOF)//while 1#
	{
		handleFunction(str1,str2,op[0]);
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