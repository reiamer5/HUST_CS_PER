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
题目1147：Jugs
时间限制：1 秒内存限制：32 兆特殊判题：是提交：209解决：175
题目描述：
    In the movie "Die Hard 3", Bruce Willis and Samuel L. Jackson were confronted with the following puzzle. 
	They were given a 3-gallon jug and a 5-gallon jug and were asked to fill the 5-gallon jug with exactly 4 gallons. 
	This problem generalizes that puzzle.
    You have two jugs, A and B, and an infinite supply of water. There are three types of actions that you can use: 
	(1) you can fill a jug, (2) you can empty a jug, and (3) you can pour from one jug to the other. Pouring from one jug
	to the other stops when the first jug is empty or the second jug is full, whichever comes first. For example, 
	if A has 5 gallons and B has 6 gallons and a capacity of 8, then pouring from A to B leaves B full and 3 gallons in A.
    A problem is given by a triple (Ca,Cb,N), where Ca and Cb are the capacities of the jugs A and B, respectively, 
	and N is the goal. A solution is a sequence of steps that leaves exactly N gallons in jug B. The possible steps are
    fill A 
    fill B 
    empty A 
    empty B 
    pour A B 
    pour B A 
    success
    where "pour A B" means "pour the contents of jug A into jug B", and "success" means that the goal has been accomplished.
    You may assume that the input you are given does have a solution.
输入：
    Input to your program consists of a series of input lines each defining one puzzle. Input for each puzzle is a single 
	line of three positive integers: Ca, Cb, and N. Ca and Cb are the capacities of jugs A and B, and N is the goal.
	You can assume 0 < Ca <= Cb and N <= Cb <=1000 and that A and B are relatively prime to one another. 
输出：
    Output from your program will consist of a series of instructions from the list of the potential output lines 
	which will result in either of the jugs containing exactly N gallons of water. The last line of output for each 
	puzzle should be the line "success". Output lines start in column 1 and there should be no empty lines nor any trailing spaces. 
样例输入：
3 5 4
5 7 3
样例输出：
fill B
pour B A
empty A
pour B A
fill B
pour B A
success
fill A
pour A B
fill A
pour A B
empty B
pour A B
success
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7870-1-1.html
*/
int Ca,Cb,Cn;
int steps[N];
int stepNum=0;
char stepsName[][12]={"success","fill A","fill B","empty A","empty B","pour A B","pour B A"};
Boolean visited[N][N];
Boolean fillA(int *A)
{
	if(*A==Ca)
	{
		return FALSE;//A已满 就不能再加了
	}
	else
	{
		*A=Ca;
	}
	return TRUE;
}

Boolean fillB(int *B)
{
	if(*B==Cb)
	{
		return FALSE;//B已满 就不能再加了
	}
	else
	{
		*B=Cb;
	}
	return TRUE;
}

Boolean emptyA(int *A)
{
	if(*A<=0)
	{
		return FALSE;//A已空 就不能空了
	}
	else
	{
		*A=0;
	}
	return TRUE;
}

Boolean emptyB(int *B)
{
	if(*B<=0)
	{
		return FALSE;//B已空 就不能空了
	}
	else
	{
		*B=0;
	}
	return TRUE;
}

Boolean pourAtoB(int *A,int *B)
{
	if(*A<=0||*B>=Cb)//A是空的或者B是满的
	{
		return FALSE;
	}
	if(*B+*A>=Cb)//A的全部倒入B中会溢出
	{	
		*A=*A-(Cb-*B);
		*B=Cb;
	}
	else
	{
		*B+=*A;
		*A=0;
	}
	return TRUE;
}

Boolean pourBtoA(int *B,int *A)
{
	if(*B<=0||*A>=Ca)//B是空的或者A是满的
	{
		return FALSE;
	}
	if(*B+*A>=Ca)//B的全部倒入A中会溢出
	{
		*B=*B-(Ca-*A);
		*A=Ca;	
	}
	else
	{
		*A+=*B;
		*B=0;
	}
	return TRUE;
}
Boolean handleFunction(int A,int B,int step)
{
	int i=0;
	int cpA=A;
	int cpB=B;
	
	if(visited[A][B]==TRUE)//当前状态达到过
	{
		return FALSE;
	}
	visited[A][B]=TRUE;	

	//printf("sasds");
	if(B==Cn)
	{
		steps[step]=i;
		stepNum=step+1;
		return TRUE;
	}
	i++;
	if(fillA(&A)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;
			return TRUE;
		}	
		A=cpA;
	}

	i++;
	if(fillB(&B)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;
			return TRUE;
		}
		B=cpB;
	}

	i++;
	if(emptyA(&A)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;
			return TRUE;
		}
		A=cpA;
	}
	
	i++;
	if(emptyB(&B)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;	
			return TRUE;
		}
		B=cpB;
	}	

	i++;
	if(pourAtoB(&A,&B)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;
			return TRUE;
		}
		A=cpA;
		B=cpB;	
	}
	
	i++;
	if(pourBtoA(&B,&A)==TRUE)
	{
		if(handleFunction(A,B,step+1)==TRUE)
		{
			steps[step]=i;
			return TRUE;
		}
	
	
	}		
	A=cpA;
	B=cpB;
	visited[A][B]=TRUE;
	return FALSE;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0,j=0;

	while(scanf("%d %d %d",&Ca,&Cb,&Cn)!=EOF)//while 1#
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				visited[i][j]=FALSE;//标记这种状态未曾达到过
		}
		handleFunction(0,0,0);
		for(i=0;i<stepNum;i++)
		{
			printf("%s\n",stepsName[steps[i]]);
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