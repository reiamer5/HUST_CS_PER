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
题目1067：n的阶乘
时间限制：1 秒内存限制：32 兆特殊判题：否提交：5914解决：2236
题目描述：
输入一个整数n，输出n的阶乘
输入：
一个整数n(1<=n<=20)
输出：
n的阶乘
样例输入：
3
样例输出：
6
来源：
2001年清华大学计算机研究生机试真题(第II套)
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7791-1-1.html
 
*/
long long factorial(int n)
{
    int i=2;
    long long sum=1;
    while(i<=n)
    {
        sum*=i;
        i++;
    }
    return sum;
}
 
//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{
    int n=0;
    while(scanf("%d",&n)!=EOF)//while 1#
    {
        printf("%lld\n",factorial(n));
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
/**************************************************************
    Problem: 1067
    User: xiaodeng1992
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:912 kb
****************************************************************/
