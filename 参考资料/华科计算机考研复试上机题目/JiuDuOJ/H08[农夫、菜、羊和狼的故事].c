#include<stdio.h>

//定义状态码
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define CANTEXIST 10//状态不可以共存(不存在对象之间会有被吃掉的可能)
#define EXIST 20//状态可以共存
#define SUCCESS 30//成功渡河
#define N 1000

#define GO 0 //从初始岸到目的岸方向
#define COME 1//从目的岸到初始岸方向
typedef int Status;
typedef int Boolean;
/*
题目描述：
有一个农夫带一只羊、一筐菜和一只狼过河.
果没有农夫看管，则狼要吃羊，羊要吃菜.
但是船很小，只够农夫带一样东西过河。
问农夫该如何解此难题？
输入：
题目没有任何输入。
输出：
题目可能有种解决方法，求出步骤最少的解决方法，
按顺序输出农夫想把羊、菜、狼全部运过河需要哪几个步骤。
如果需要将羊带过河去则输出"sheep_go"。
如果需要将羊带回来则输出"sheep_come"。
如果需要将菜带过河去则输出"vegetable_go"。
如果需要将菜带回来则输出"vegetable_come"。
如果需要将狼带过河去则输出"wolf_go"。
如果需要将狼带回来则输出"wolf_come"。
如果需要空手返回则输出"nothing_come"。
如果需要空手过河则输出"nothing_go"。
每输出一种方案，输出一行"succeed"。
样例输入：
样例输出：
提示：
题目可能有多组解决方法，每种方法输出后要再空一行。
一种方法中的多句话，每句话占一行。

*/

char pathStr[][20]= {"nothing_go","wolf_go","sheep_go","vegetable_go","nothing_come","wolf_come","sheep_come","vegetable_come"};
int mark[2][16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //标记两岸对象的状态 避免重复搜索
int path[N];//记录运送的顺序 pathStr中的运送方式的下标
int ways[4][4]= {1,0,0,0, //只有人过河
                 1,1,0,0,//人和狼
                 1,0,1,0,//人和羊
                 1,0,0,1	//人和菜
                };

//检测该种状态是否可以存在
Boolean safe(int state[4])
{
    if(state[0]==1)
        return TRUE;//农夫在 安全
    if(	(state[0]==0&&state[1]==0&&state[2]==0&&state[3]==1)||//只有菜单独在一岸
            (state[0]==0&&state[1]==0&&state[2]==1&&state[3]==0)||//只有羊单独在一岸
            (state[0]==0&&state[1]==1&&state[2]==0&&state[3]==0)||//只有狼单独在一岸
            (state[0]==0&&state[1]==1&&state[2]==0&&state[3]==1)||//狼和菜在一岸
            (state[0]==0&&state[1]==0&&state[2]==0&&state[3]==0) )//该岸为空
    {
        return TRUE;
    }
    return FALSE;
}

//检测A,B两岸的状态
Boolean check(int A[4],int B[4])
{
    if(B[0]==1&&B[1]==1&&B[2]==1&&B[3]==1 &&
            A[0]==0&&A[1]==0&&A[2]==0&&A[3]==0)
        return SUCCESS;
    if(safe(A)==TRUE&&safe(B)==TRUE)
    {
        return EXIST;
    }
    return CANTEXIST;
}
//当前的A,B岸的状态 是否可以按第w种方式渡河后 direction表示方向
Boolean checkAll(int w,int A[4],int B[4],int direction)
{
    int AA[4]= {A[0]-ways[w][0],A[1]-ways[w][1],A[2]-ways[w][2],A[3]-ways[w][3]};
    int BB[4]= {B[0]+ways[w][0],B[1]+ways[w][1],B[2]+ways[w][2],B[3]+ways[w][3]};
    int markIndexA=0;
    int markIndexB=0;
    if( AA[0]>=0&&AA[1]>=0&&AA[2]>=0&&AA[3]>=0 &&safe(AA)==TRUE&&safe(BB)==TRUE)//可以渡河:1 要运送的对象存在 2 运送后两岸的状态是安全的
    {
        markIndexA=AA[0]*8+AA[1]*4+AA[2]*2+AA[3]*1;
        markIndexB=BB[0]*8+BB[1]*4+BB[2]*2+BB[3]*1;
        //检测运送过后的状态 是否是已经搜索过了
        if(mark[direction][markIndexA]==1&&mark[1-direction][markIndexB]==1)//这里注意A,B是相对的 应该根据direction绝定方向 从而正确的标记状态
            return FALSE;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//回朔法求解渡河方式
Status tryCross(int A[4],int B[4],int step,int direction)
{
    int w=0,k=0;
    int markIndexA,markIndexB;
    for(w=0; w<4; w++) //for #1 依次试探各种方式
    {
        if(checkAll(w,A,B,direction)==TRUE)//if #1  可以渡河  进行试探
        {
            A[0]=A[0]-ways[w][0];
            A[1]=A[1]-ways[w][1];
            A[2]=A[2]-ways[w][2];
            A[3]=A[3]-ways[w][3];
            B[0]=B[0]+ways[w][0];
            B[1]=B[1]+ways[w][1];
            B[2]=B[2]+ways[w][2];
            B[3]=B[3]+ways[w][3];
            path[step]=w+direction*4;//标记渡河的方式  带走了那些对象
            markIndexA=A[0]*8+A[1]*4+A[2]*2+A[3]*1;//标记一个状态 表示该种方式已经试探过了
            markIndexB=B[0]*8+B[1]*4+B[2]*2+B[3]*1;
            mark[direction][markIndexA]=1;
            mark[1-direction][markIndexB]=1;

            if(direction==GO&&SUCCESS==check(A,B))//找到一种可行法方案
            {
                for(k=0; k<step+1; k++)
                {
                    printf("%s\n",pathStr[path[k]]);
                }
                printf("succeed\n");
            }
            else
            {
                tryCross(B,A,step+1,1-direction);//试探下一步
            }
            //回朔 恢复现场
            mark[direction][markIndexA]=0;
            mark[1-direction][markIndexB]=0;

            A[0]=A[0]+ways[w][0];
            A[1]=A[1]+ways[w][1];
            A[2]=A[2]+ways[w][2];
            A[3]=A[3]+ways[w][3];
            B[0]=B[0]-ways[w][0];
            B[1]=B[1]-ways[w][1];
            B[2]=B[2]-ways[w][2];
            B[3]=B[3]-ways[w][3];
        }//end:if #1

    }//end:for #1

    return OK;
}

//业务处理函数:输入数据 调用相关函数完成任务 返回处理结果
Status service()
{

    //顺序：农夫 狼 羊  菜
    int A[]= {1,1,1,1}; //开始的一岸
    int B[]= {0,0,0,0}; //对岸
    tryCross(A,B,0,GO);
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
