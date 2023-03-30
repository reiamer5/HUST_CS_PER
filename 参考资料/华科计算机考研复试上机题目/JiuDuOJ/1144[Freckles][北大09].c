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

#define M 10000
#define N 200
#define INF 0xffffffff
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1144：Freckles
时间限制：1 秒内存限制：32 兆特殊判题：否提交：1136解决：570
题目描述：
    In an episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad's back to form a picture of the Liberty Bell.
	Alas, one of the freckles turns out to be a scar, so his Ripley's engagement falls through. 
    Consider Dick's back to be a plane with freckles at various (x,y) locations. Your job is to tell Richie how to connect the dots 
	so as to minimize the amount of ink used. Richie connects the dots by drawing straight lines between pairs, 
	possibly lifting the pen between lines. When Richie is done there must be a sequence of connected lines from 
	any freckle to any other freckle. 
输入：
    The first line contains 0 < n <= 100, the number of freckles on Dick's back. For each freckle, a line follows; 
	each following line contains two real numbers indicating the (x,y) coordinates of the freckle.
输出：
    Your program prints a single real number to two decimal places: the minimum total length of ink lines that can 
	connect all the freckles.
样例输入：
3
1.0 1.0
2.0 2.0
2.0 4.0
样例输出：
3.41
来源：
2009年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7867-1-1.html

*/

double points[N][2];//点
double lines[M][3];//直线
Boolean visitedL[M];
Boolean visitedV[N];
Status handleFunction(int num)
{
	int i=0,j=0,k=0,l=0;
	int linesNum=0;
	int vNum=0;
	double sum=0.0;
	double minLen=0.0;
	int minLIndex=0;
	int x1=0,x2=0;
	int mx1=0,mx2=0;
	for(i=0;i<num-1;i++)
	{
		visitedV[i]=FALSE;
		for(j=i+1;j<num;j++)
		{
			//记录直线的坐标
			lines[linesNum][0]=i;
			lines[linesNum][1]=j;
			//求直线的长度
			lines[linesNum][2]=sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
		//	printf("%lf\n",lines[linesNum][2]);
			visitedL[linesNum]=FALSE;//访问标记
			linesNum++;
		}
	}	

	visitedV[i]=FALSE;
	k=0;//第一个访问节点
	visitedV[k]=TRUE;
	vNum=1;
	while(vNum<num)//while 1#
	{
		minLen=INF;
		minLIndex=-1;
		for(l=0;l<linesNum;l++)
		{
			if(visitedL[l]==TRUE||lines[l][2]>minLen)
				continue;
			x1=(int)lines[l][0];
			x2=(int)lines[l][1];
			if( (visitedV[x1]==FALSE&&visitedV[x2]==TRUE)||(visitedV[x1]==TRUE&&visitedV[x2]==FALSE) )
			{
				minLen=lines[l][2];//选出最小的边
				minLIndex=l;
				mx1=x1;
				mx2=x2;
			}
		}
		if(minLIndex!=-1)
		{
			sum+=minLen;	
			//标记已经访问
			visitedL[minLIndex]=TRUE;
			visitedV[mx1]=visitedV[mx2]=TRUE;
			vNum++;
		}
		
	}//end:while 1#

	printf("%.2lf\n",sum);
	return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int n=0;
	int i=0;
	while(scanf("%d",&n)!=EOF)//while 1#
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&points[i][0],&points[i][1]);
		}
		handleFunction(n);
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