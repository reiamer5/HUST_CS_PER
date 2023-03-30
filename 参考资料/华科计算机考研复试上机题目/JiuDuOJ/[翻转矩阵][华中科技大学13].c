#include<stdio.h>
#include<math.h>
typedef int Status;
typedef int Boolean;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 200
int matrix[N][N];
//初始化矩阵 
Status initMatrix(int n)
{
	int i=0,j=0;
	int k=1;
	if(n>N)
	{
		printf("Out of boundary!\n");
		return ERROR;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j]=k;
			k++;
		}
	}
}
//打印矩阵
Status printMatrix(int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//翻转矩阵
Status tmatrix(int n,int startIndex,int startNum)
{
	
	int i=0,k=0;

	if(n==0)
	{
		return OK;
	}
	if(n==1)
	{
		matrix[startIndex][startIndex]=startNum;
		return OK;
	}
	//横	
	k=startIndex+n;
	for(i=startIndex;i<k;i++)
	{
		matrix[startIndex][i]=startNum++;
	}
	//竖
	k=startIndex+n-1;
	for(i=startIndex+1;i<k;i++)
	{
		matrix[i][k]=startNum++;
	}
	//横
	k=startIndex+n-1;
	for(i=startIndex+n-1;i>=startIndex;i--)
	{
		matrix[k][i]=startNum++;
	}
	//竖
	for(i=startIndex+n-2;i>startIndex;i--)
	{
		matrix[i][startIndex]=startNum++;
	}
	return tmatrix(n-2,startIndex+1,startNum);
}

//业务处理函数
Status service()
{
	int n=0;

	while(scanf("%d",&n)!=EOF)
	{
		tmatrix(n,0,1);
		printMatrix(n);
	}
	return OK;
}


int main()
{
	if(ERROR==service())
	{
		printf("ERROR!\n");
		return ERROR;
	}
	return OK;
}