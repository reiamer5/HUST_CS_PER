#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

double min(double a,double b,double c)
{
	if(a<b)
	{
		if(a<c)
		{
			return a;
		}
		return c;
	}
	if(b<c)
	{
		return b;
	}
	return c;
}

double max(double a,double b,double c)
{
	if(a>b)
	{
		if(a>c)
		{
			return a;
		}
		return c;
	}
	if(b>c)
	{
		return b;
	}
	return c;
}
double jdabs(double a,double b)
{
	return (a-b)>0? a-b:b-a;
}

BOOL isTolerance(double a,double b,double T,double limitation)
{
	if(jdabs(a,b)<=T && a<=limitation && b<limitation && a>=0 && b>=0)
	{
		return TRUE;
	}
	return FALSE;
}

double closet(double a,double b,double c)
{
	double diff1,diff2;

	diff1=jdabs(a,c);
	diff2=jdabs(b,c);

	if(diff1<diff2)
		return (a+c)/2;
	return (b+c)/2;
}

double judge(double p,double t,double g1,double g2,double g3,double g)
{
	if(isTolerance(g1,g2,t,p)==TRUE)
	{
		return (g1+g2)/2;
	}
	if( (isTolerance(g1,g3,t,p)==TRUE) && (isTolerance(g2,g3,t,p)==TRUE) )
	{
		return max(g1,g2,g3);
	}

	if((isTolerance(g1,g3,t,p)==FALSE) && (isTolerance(g2,g3,t,p)==FALSE))
	{
		return g;
	}

	return closet(g1,g2,g3);

}

int main()
{
	double g1,g2,g3,g;
	double p,t;

	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&t,&g1,&g2,&g3,&g)!=EOF)
	{
		printf("%.1lf\n",judge(p,t,g1,g2,g3,g));
	}

	return 0;
}