#include<stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXLEN 1024
typedef int BOOL;

BOOL specialChar(char c)
{
	if(c==' ' || c=='o')
	{
		return TRUE;
	}
	return FALSE;
}
int strlen(char str[])
{
	int i=0;
	while(str[i++]!='\0')
		;
	return i;
}
BOOL patternA(char str[])
{
	if(strlen(str)==4 && str[0]=='z' && str[1]=='o' && str[2]=='j')
	{
		return TRUE;
	}
	return FALSE;
}

BOOL patternB(char str[])
{
	int i=0;
	int j=0;

	for(i=0,j=strlen(str)-2;i<j && (str[i]==str[j]) && ( specialChar(str[i])==TRUE);i++,j-- )
	{
		//empty...
	}

	if(!(i<j))
	{
		return FALSE;
	}

	if(str[i]=='z' && str[i+1]=='o' && str[j]=='j')
	{
		return TRUE;
	}

	return FALSE;
}

BOOL patternC(char str[])
{
	int i=0;
	int j=0;
	int numL=0,numR=0,numO=0;
	
	char mark=str[0];

	for(i=0;str[i]!='z'&&i<strlen(str);i++)
	{
		if(str[i]!=mark)
			return FALSE;
	}

	numL=i;

	for(i++;str[i]!='j'&&i<strlen(str);i++)
	{
		if(str[i]!='o')
			return FALSE;
		numO++;
	}
	for(i++;i<strlen(str)-1;i++)
	{
		if(str[i]!=mark)
			return FALSE;
		numR++;
	}
	if(numO>1&&(numR%numL)==0)
	{
		return TRUE;
	}
	return FALSE;
}
int main()
{

	char str[MAXLEN];
	
	while(scanf("%s",str)!=EOF)
	{
		if(strlen(str)<3||strlen(str)>1000)
		{
			printf("Wrong Answer\n");
		}
		else if( (patternA(str)==TRUE) || (patternB(str)==TRUE) || (patternC(str)==TRUE) )
		{
			printf("Accepted\n");
		}
		else
		{
			printf("Wrong Answer\n");
		}
	}

	return 0;
}