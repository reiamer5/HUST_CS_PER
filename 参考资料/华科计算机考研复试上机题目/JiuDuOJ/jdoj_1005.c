#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define NULL 0

typedef int BOOL;

typedef struct GradeNode
{
	float GE;
	float GI;
	float AVG;//(GE+GI)/2
}GradeNode,*PGrade;

typedef struct StuNode
{
	int ID;
	PGrade pG;
	int choices[3];
	struct StuNode *next;
}StuNode,*StuList;

typedef struct SchNode
{
	int ID;
	int P;//可接收的人数
	int V;//剩余的人数
	StuList stuList;//接收的学生的信息链表
	GradeNode *LG;//当前录取学生的最低分
}SchNode,*SchList;

//if a==b return TRUE
//else return false
BOOL EQ(GradeNode* a,GradeNode* b)
{
	if(a->AVG==b->AVG && a->GE==b->GE)
		return TRUE;
	return FALSE;
}

BOOL QT(GradeNode *a,GradeNode *b)
{
	if((a->AVG>b->AVG) ||(a->AVG==b->AVG && a->GE>b->GE))
		return TRUE;
	return FALSE;
}


int main()
{
	int N;//学生总数
	int M;//学校数
	int K;//学生的选择数
	int i=0;
	SchList schList;
	StuList stuList;
	StuNode *sp,*sq,*sL,*sr,*ss;
	GradeNode *pG;
	float GE,GI;
	int choices[3];
	while(scanf("%d %d %d",&N,&M,&K)!=EOF)
	{
		i=0;	
		
		schList=(SchNode *)malloc( sizeof(SchNode)*M );
		
		sq=sL=(StuNode*)malloc(sizeof(StuNode));
		sq->next=NULL;

		for(i=0;i<M;i++)//读取学校招生人数 初始化学校的信息
		{
			scanf("%d",&schList[i].V);
			schList[i].ID=i;
			schList[i].P=0;
			schList[i].stuList=(StuNode*)malloc(sizeof(StuNode));
			schList[i].stuList->next=NULL;
			schList[i].LG=(GradeNode*)malloc(sizeof(GradeNode));
			schList[i].LG->GE=100.0;
			schList[i].LG->GI=100.0;
			schList[i].LG->AVG=100.0;

		}
		
		for(i=0;i<N;i++)
		{
			scanf("%f %f %d %d %d",&GE,&GI,&choices[0],&choices[1],&choices[2]);
		
			//成绩节点
			pG=(GradeNode*)malloc(sizeof(GradeNode));
			pG->GE=GE;
			pG->GI=GI;
			pG->AVG=(GE+GI)/2;
			
			//学生信息节点
			sp=(StuNode*)malloc(sizeof(StuNode));
			sp->ID=i;
			sp->pG=pG;
			sp->choices[0]=choices[0];
			sp->choices[1]=choices[1];
			sp->choices[2]=choices[2];

			sq=sL;
			while(sq && sq->next && (QT(sp->pG,sq->next->pG)==FALSE))//非递减顺序插入
			{
				sq=sq->next;
			}
			sp->next=sq->next;
			sq->next=sp;
		}
		
		
		/* ---------test--------------------------------------
		sp=sL->next;
		while(sp)
		{
			printf("%d %.2f %.2f %.2f %d %d %d \n",sp->ID,sp->pG->GE,sp->pG->GI,sp->pG->AVG,sp->choices[0],sp->choices[1],sp->choices[2]);
			sp=sp->next;
		}
	
		----------------------------------------------------*/

		sq=sL->next;
		while(sq)
		{
			int loop=TRUE;
			for(i=0;i<3&&loop;i++)
			{
				if( (schList[sq->choices[i]].P<schList[sq->choices[i]].V) ||
					( (schList[sq->choices[i]].P>=schList[sq->choices[i]].P)&&EQ(schList[sq->choices[i]].LG,sq->pG)) )
				{
					schList[sq->choices[i]].P++;
					sr=schList[sq->choices[i]].stuList;
					while(sr && sr->next && sq->ID>sr->next->ID)
					{
						sr=sr->next;
					}

					if(i<3&&QT(schList[sq->choices[i]].LG,sq->pG))//更新当前院校的最低录取分数
					{
						schList[sq->choices[i]].LG->GE=sq->pG->GE;
						schList[sq->choices[i]].LG->GI=sq->pG->GI;
						schList[sq->choices[i]].LG->AVG=sq->pG->AVG;
					}

					ss=sq->next;//保存下一个被考察的学生的信息
					sq->next=sr->next;
					sr->next=sq;
					sq=ss;//将保存的学生节点作为下一个被考察的节点

					loop=FALSE;
				}//fi
			}//ed ..for
			if(sq&&loop==TRUE)
				sq=sq->next;//没有被录取 直接进入下一个
		//	printf("=====\n");
		}//ed..while..sq

		for(i=0;i<M;i++)
		{
			
			if(schList[i].P==0)
			{
				printf("\n");
			}
			else
			{
				sp=schList[i].stuList->next;
				while(sp&&sp->next)
				{
					printf("%d ",sp->ID);
					sp=sp->next;
				}
				printf("%d\n",sp->ID);
			}
		}
		free(schList);
	}//1...while

	return 0;
}