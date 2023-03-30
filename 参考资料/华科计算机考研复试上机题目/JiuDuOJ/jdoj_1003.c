#include<stdio.h>

#define MAXLEN 16

void deleteChar(char str[],char c)
{
	int i=0,j=0;
	while(str[i]!='\0')
	{
		if(str[i]!=c)
		{
			str[j++]=str[i];
		}
		i++;
	}
	str[j]='\0';
}

int str2Int(char str[])
{
	int i=0;
	int sign=1;
	int result=0;
	while(str[i]==' ')
	{
		i++;
	}

	sign=(str[i]=='-'?-1:1);
	
	if(str[i]=='+' || str[i]=='-')
	{
		i++;
	}
	while(str[i]!='\0')
	{
		result=10*result+str[i++]-'0';
	}

	return result*sign;
}

int sumStr(char str1[],char str2[])
{
	deleteChar(str1,',');
	deleteChar(str2,',');
	
	return str2Int(str1)+str2Int(str2);
}
int main()
{
	char str1[MAXLEN],str2[MAXLEN];

	while(scanf("%s %s",str1,str2)!=EOF)
	{
		printf("%d\n",sumStr(str1,str2));
	}

	return 0;
}