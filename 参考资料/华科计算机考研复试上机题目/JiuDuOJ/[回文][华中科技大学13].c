#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef int Status;
typedef int Boolean;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define N 1010
Boolean isMark(char c)
{
	if(c==' '||c=='.'||c=='?'||c==':'||c=='\''||c=='\"'||c==':')
	{
		return TRUE;
	}
	return FALSE;
}
Status huiwen(char str[N])
{
	
	int i=0,j=0;
	int maxi=0,maxj=0;
	int strLen=strlen(str);
	int low=0,high=0;
	int flag=TRUE;
	for(i=0;i<strLen-1;i++)
	{
		for(j=i+1;j<strLen;j++)
		{
			low=i;
			high=j;
			while(low<high)
			{
				flag=TRUE;
				if(tolower(str[low])==tolower(str[high]))
				{
					low++;
					high--;
				}
				else if(isMark(str[low])==TRUE)
				{//He say:Madam,I'm Adam.
					low++;
				}
				else if(isMark(str[high])==TRUE)
				{
					high--;
				}
				else
				{
					flag=FALSE;
					break;
				}
			}
			if(flag==TRUE&&((j-i)>(maxj-maxi)))
			{
				maxi=i;
				maxj=j;
			}
		}
	}
	if(maxi==0&&maxj==0)
	{
		return OK;
	}
	while(maxi<=maxj)
	{
		printf("%c",str[maxi++]);
	}
	return OK;
}

//业务处理函数
Status service()
{
	char str[N];

	while(gets(str)!=NULL)
	{
		huiwen(str);
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