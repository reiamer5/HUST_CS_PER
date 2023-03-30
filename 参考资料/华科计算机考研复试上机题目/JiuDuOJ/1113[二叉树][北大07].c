#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
#include<math.h>
//定义状态码
#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Boolean;

typedef int ElemType;

//#define M 1000
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1113：二叉树
时间限制：1 秒内存限制：32 兆特殊判题：否提交：3859解决：1137
题目描述：
 

    如上所示，由正整数1，2，3……组成了一颗特殊二叉树。我们已知这个二叉树的最后一个结点是n。现在的问题是，
	结点m所在的子树中一共包括多少个结点。

    比如，n = 12，m = 3那么上图中的结点13，14，15以及后面的结点都是不存在的，结点m所在子树中包括的结点有3，6，7，12，
	因此结点m的所在子树中共有4个结点。
输入：
    输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。
	最后一组测试数据中包括两个0，表示输入的结束，这组数据不用处理。
输出：
    对于每一组测试数据，输出一行，该行包含一个整数，给出结点m所在子树中包括的结点的数目。
样例输入：
3 12
0 0
样例输出：
4
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7836-1-1.html


*/
int  handleFunction(int m,int n)
{
	int levelCount=0;//节点为满层的层数
	int li=m,ri=m;
	int sum=1;
	while(li<n&&ri<n)
	{
		li=li<<1;
		ri=1+(ri<<1);
		levelCount++;
	}
	
	sum=(int)pow(2,levelCount)-1;//前面满层的节点数
	//printf("%d--\n",li);
	if(li<=n)
	{
		sum=sum+(n-li+1);
	}
	return sum;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int m=0,n=0;
	scanf("%d %d",&m,&n);
	while(!(m==0&&n==0))//while 1#
	{
		printf("%d\n",handleFunction(m,n));
		scanf("%d %d",&m,&n);
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