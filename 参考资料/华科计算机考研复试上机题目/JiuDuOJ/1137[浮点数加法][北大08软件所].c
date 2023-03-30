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
#define N 120

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1137：浮点数加法
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2215解决：628
题目描述：
求2个浮点数相加的和
题目中输入输出中出现浮点数都有如下的形式：
P1P2...Pi.Q1Q2...Qj
对于整数部分，P1P2...Pi是一个非负整数
对于小数部分，Qj不等于0
输入：
对于每组案例，第1行是测试数据的组数n，每组测试数据占2行，分别是两个加数。
每组测试数据之间有一个空行，每行数据不超过100个字符
输出：
每组案例是n行，每组测试数据有一行输出是相应的和。
输出保证一定是一个小数部分不为0的浮点数
样例输入：
2
0.111111111111111111111111111111
0.111111111111111111111111111111
10000000.655555555555555555555555555555
1.444444444444444444444444444445
样例输出：
0.222222222222222222222222222222
10000002.1
来源：
2008年北京大学软件所计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7860-1-1.html
*/
//将str1和str2中的内容转换为十进制数字相加，结果存放在str3中
Status add(char str1[N], char str2[N],char str3[N])
{
	int strLen1=strlen(str1);
	int strLen2=strlen(str2);
	char* pointP1=strchr(str1,'.');//字符串中小数点的位置
	char* pointP2=strchr(str2,'.');	
	char *p1=strchr(str1,'\0')-1;
	char *p2=strchr(str2,'\0')-1;
	
	int i1=p1-pointP1;//str1小数的位数
	int i2=p2-pointP2;//str2小数的位数
	int j1=strLen1-i1-1;//str1整数数的位数
	int j2=strLen2-i2-1;//str2整数数的位数
	int i=0;
	int j=0;
	int c=0;//进位
	int sum=0;//每一位相加的和

	//计算和的位数的最大值
	if(i1>i2)
	{
		i=i1;//
	}
	else
	{	
		i=i2;
	}
	if(j1>j2)
	{
		i+=j1;
	}
	else
	{	
		i+=j2;
	}

	i+=3;//防止两数相加 长度增加一位 小数1位 结束符一位
	str3[i]='\0';
	i--;

	if(i1>i2)//将字符串str1多余部分直接赋给str3
	{	
		while(i1>i2)
		{
			str3[i]=*p1;
			i1--;
			i--;
			p1--;
		}
	}
	else if(i1<i2)//将字符串str2多余部分直接赋给str3
	{	
		while(i2>i1)
		{
			str3[i]=*p2;
			i2--;
			i--;
			p2--;
		}
	}
	while(p1!=pointP1)//处理小数部分
	{
		sum=(*p1)+(*p2)-'0'-'0'+c;
		c=sum/10;
		str3[i]=sum%10+'0';
		p1--;
		p2--;
		i--;
	}

	str3[i]='.';//处理小数点
	i--;
	p1--;
	p2--;

	//while 1# 处理整数相加
	while(j2>=1&&j1>=1)
	{
		sum=(*p1)+(*p2)-'0'-'0'+c;
		c=sum/10;
		str3[i]=sum%10+'0';
		p1--;
		p2--;
		i--;
		j2--;
		j1--;
	}	
	//printf("%d %d %d\n",i,strLen1,strLen2);

	while(j1>=1)
	{
		sum=(*p1)-'0'+c;
		c=sum/10;
		str3[i]=sum%10+'0';
		p1--;
		i--;
		j1--;
	}

	while(j2>=1)
	{
		sum=(*p2)-'0'+c;
		c=sum/10;
		str3[i]=sum%10+'0';	
	
		p2--;	
		i--;
		j2--;
	}
	str3[i]=c+'0';
	i--;
	

	//printf("**%d %d %d\n",i,j1,j2);
	if(i==0)//处理两数相加 长度增加一位的情况
	{
		i++;
		while(str3[i]!='\0')
		{
			str3[i-1]=str3[i];
			i++;
		}
		str3[i-1]=str3[i];	
	}
	i=strlen(str3)-1;
	 
	while(str3[i]=='0'&&(str3[i]!='.'))//处理小数部分多余0的情况
	{
		i--;
		
	}
	if(str3[i]=='.')
		str3[i+2]='\0';
	else
		str3[i+1]='\0';

	i=0;//处理首部多余0的情况
	while(str3[i]=='0')
	{
		i++;
	}
	j=0;
	if(str3[i]=='.')
		i--;
	while(str3[i]!='\0')
	{
		str3[j++]=str3[i++];
	}
	str3[j]='\0';
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	char str1[N][N],str2[N],str3[N];
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%s",str1,str2);
			add(str1,str2,str3);
			printf("%s\n",str3);
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