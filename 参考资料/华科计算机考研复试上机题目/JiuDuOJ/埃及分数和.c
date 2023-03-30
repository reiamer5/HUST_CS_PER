#include<stdio.h>

typedef int Status;
typedef int Boolean;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 100

Status handleFunction(int a,int b)
{
	int num[N];
	int count=0;
	int c=0;
	int i=0;
	int ta=a,tb=b;
	if(a>b)
	{
		printf("illegal parameters!\n");
		return ERROR;
	}
	if(a==1||b%a==0)
	{
		printf("%d/%d=%d/%d\n",a,b,1,b/a);
		return OK;
	}

	while(b%a!=0)
	{
		c=((int)b/a)+1;
		num[count++]=c;
		a=a*c-b;
		b=b*c;
	}
	num[count++]=b;
	printf("%d/%d=",ta,tb);
	while(i<count-1)
	{
		printf("%d/%d+",1,num[i]);
		i++;
	}
	printf("%d/%d\n",1,b/a);
	return OK;
}

Status service()
{
	int a=0,b=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		handleFunction(a,b);
	}
	return OK;
}
int main()
{
	if(ERROR==service())
	{
		printf("ERROR");
		return ERROR;
	}
	return OK;
}