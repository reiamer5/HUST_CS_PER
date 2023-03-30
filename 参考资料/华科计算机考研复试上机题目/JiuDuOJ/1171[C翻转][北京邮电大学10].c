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
//#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1171：C翻转
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3938解决：1282
题目描述：
首先输入一个5 * 5的数组，然后输入一行，这一行有四个数，前两个代表操作类型，后两个数x y代表需操作数据为以x y为左上角的那几个数据。
操作类型有四种：  
1 2 表示：90度，顺时针，翻转4个数  
1 3 表示：90度，顺时针，翻转9个数  
2 2 表示：90度，逆时针，翻转4个数  
2 3 表示：90度，逆时针，翻转9个数 
输入：
输入有多组数据。
每组输入一个5 * 5的数组，然后输入一行，这一行有四个数，前两个代表操作类型，后两个数x y代表需操作数据为以x y为左上角的那几个数据。
输出：
输出翻转后的数组。
样例输入：
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
1 3 1 1
样例输出：
11 6 1 4 5
12 7 2 9 10
13 8 3 14 15
16 17 18 19 20
21 22 23 24 25
来源：
2010年北京邮电大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7894-1-1.html


*/
Status transepose(int data[6][6],int p1,int p2,int x,int y)
{
	int i=0,j=0;
	int d1=0;
	if(p1==1&&p2==2)//1 2 表示：90度，顺时针，翻转4个数  
	{
		d1=data[x][y];
		data[x][y]=data[x+1][y];
		data[x+1][y]=data[x+1][y+1];
		data[x+1][y+1]=data[x][y+1];
		data[x][y+1]=d1;

	}
	else if(p1==1&&p2==3)//1 3 表示：90度，顺时针，翻转9个数  
	{
		d1=data[x][y+2];
		data[x][y+2]=data[x][y+1];
		data[x][y+1]=data[x][y];

		data[x][y]=data[x+1][y];
		data[x+1][y]=data[x+2][y];
		data[x+2][y]=data[x+2][y+1];
		data[x+2][y+1]=data[x+2][y+2];
		data[x+2][y+2]=data[x+1][y+2];
		data[x+1][y+2]=d1;

		d1=data[x][y+2];
		data[x][y+2]=data[x][y+1];
		data[x][y+1]=data[x][y];

		data[x][y]=data[x+1][y];
		data[x+1][y]=data[x+2][y];
		data[x+2][y]=data[x+2][y+1];
		data[x+2][y+1]=data[x+2][y+2];
		data[x+2][y+2]=data[x+1][y+2];
		data[x+1][y+2]=d1;
	}
	else if(p1==2&&p2==2)//2 2 表示：90度，逆时针，翻转4个数  
	{
		d1=data[x][y];
		data[x][y]=data[x][y+1];
		data[x][y+1]=data[x+1][y+1];
		data[x+1][y+1]=data[x+1][y];
		data[x+1][y]=d1;
	}
	else//2 3 表示：90度，逆时针，翻转9个数 
	{
		d1=data[x][y+2];
		data[x][y+2]=data[x+1][y+2];
		data[x+1][y+2]=data[x+2][y+2];
		data[x+2][y+2]=data[x+2][y+1];
		data[x+2][y+1]=data[x+2][y];	
		data[x+2][y]=data[x+1][y];
		data[x+1][y]=data[x][y];
		data[x][y]=data[x][y+1];
		data[x][y+1]=d1;
		
		d1=data[x][y+2];
		data[x][y+2]=data[x+1][y+2];
		data[x+1][y+2]=data[x+2][y+2];
		data[x+2][y+2]=data[x+2][y+1];
		data[x+2][y+1]=data[x+2][y];	
		data[x+2][y]=data[x+1][y];
		data[x+1][y]=data[x][y];
		data[x][y]=data[x][y+1];
		data[x][y+1]=d1;			
	}

	for(i=1;i<=5;i++)
	{
		for(j=1;j<=4;j++)
		{
			printf("%d ",data[i][j]);
		}
		printf("%d\n",data[i][j]);
	}
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0,k=0;
	int data[6][6];
	int tempdata[25];
	int p1=0,p2=0,x=0,y=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		k=0;
		tempdata[0]=n;
		for(i=1;i<25;i++)
		{
			scanf("%d",tempdata+i);
		}
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=5;j++)
			{
				data[i][j]=tempdata[k++];
			}
		}
		scanf("%d %d %d %d",&p1,&p2,&x,&y);

		transepose(data,p1,p2,x,y);
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