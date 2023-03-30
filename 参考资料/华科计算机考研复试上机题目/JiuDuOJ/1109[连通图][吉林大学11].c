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
#define N 1002

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1109：连通图
时间限制：1 秒内存限制：32 兆特殊判题：否提交：2281解决：1181
题目描述：
    给定一个无向图和其中的所有边，判断这个图是否所有顶点都是连通的。
输入：
    每组数据的第一行是两个整数 n 和 m（0<=n<=1000）。n 表示图的顶点数目，m 表示图中边的数目。
	如果 n 为 0 表示输入结束。随后有 m 行数据，每行有两个值 x 和 y（0<x, y <=n），表示顶点 x 和 y 相连，
	顶点的编号从 1 开始计算。输入不保证这些边是否重复。
输出：
    对于每组输入数据，如果所有顶点都是连通的，输出"YES"，否则输出"NO"。
样例输入：
4 3
1 2
2 3
3 2
3 2
1 2
2 3
0 0
样例输出：
NO
YES
来源：
2011年吉林大学计算机研究生机试真题
*/

int data[N][N];
int vnum=0;	
int visited[N];//标记是否访问	
int count=0;
Status DFS(int v)
{
	int k=0;
	count++;
	visited[v]=TRUE;

	if(count==vnum)
	{
		printf("YES\n");
		return OK;
	}

	for(k=1;k<=vnum;k++)
	{
		if(data[v][k]==1&&visited[k]==FALSE)
		{
			DFS(k);
		}
	}

	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0,m=0;
	int i=0;
	int x=0,y=0;
	while(scanf("%d %d",&n,&m),n)//while 1#
	{
		vnum=n;
		for(i=1;i<=n;i++)
		{
			memset(data[i],0,N);
		}
		memset(visited,FALSE,N);//初试标记所有顶点未访问
		count=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			data[x][y]=data[y][x]=1;
		}
		DFS(1);
		if(count<vnum)
		{
			printf("NO\n");
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