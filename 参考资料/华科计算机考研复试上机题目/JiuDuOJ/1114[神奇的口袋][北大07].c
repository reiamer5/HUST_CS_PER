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

typedef int ElemType;

#define M 40
#define N 1000

//const int MAXINT =((unsigned int)-1)>>1;
//const int MININT= ~ (((unsigned int)-1)>>1);
/*************************题目说明********************/
/*
题目1114：神奇的口袋
时间限制：1 秒内存限制：32 兆特殊判题：否提交：788解决：471
题目描述：
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，
每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，
John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
输入：
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出：
输出不同的选择物品的方式的数目。
样例输入：
3
20
20
20
样例输出：
3
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7837-1-1.html
*/

int weights[N];
int count=0;
int trySelect(int sequence,int wayNum,int weight)
{
	int wayNum1=0;
	int wayNum2=0;
	if(sequence<count&&weight+weights[sequence]==M)
	{
		wayNum1=wayNum+1;
		wayNum2=trySelect(1+sequence,wayNum,weight);
		return wayNum1+wayNum2;
	}
	if(sequence==count)
	{
		return wayNum;
	}
	if(weight+weights[sequence]<M)
	{
		wayNum1=trySelect(1+sequence,wayNum,weight+weights[sequence]);
		wayNum2=trySelect(1+sequence,wayNum,weight);
		return wayNum1+wayNum2;
	}
	wayNum2=trySelect(1+sequence,wayNum,weight);
	return wayNum2;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
	int i=0;
	while(scanf("%d",&count)!=EOF)//while 1#
	{
		for(i=0;i<count;i++)
		{
			scanf("%d",weights+i);
		}
		printf("%d\n",trySelect(0,0,0));
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