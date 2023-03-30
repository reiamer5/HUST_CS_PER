#include<stdio.h>

#define ASIZE 10
#define TRUE 1
#define FALSE 0
int main()
{
	int M=0;
	int N=0;
	int A[ASIZE][ASIZE]={0};
	int B[ASIZE][ASIZE]={0};
	int S[ASIZE][ASIZE]={0};
	int C[ASIZE]={0};
	int numGr=0;//×éÊý

	int i=0;
	int j=0;
	
	int isZero=TRUE;

	scanf("%d %d",&M,&N);
	while(M!=0)
	{
		C[numGr]=0;

		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&A[i][j]);
			}
		}

		for(i=0;i<M;i++)
		{
			isZero=TRUE;
			for(j=0;j<N;j++)
			{
				scanf("%d",&B[i][j]);
				S[i][j]=A[i][j]+B[i][j];

				if((S[i][j]!=0))
				{
					isZero=FALSE;
				}
			}
			if(isZero==TRUE)
			{
				C[numGr]++;
			}
		}

		for(j=0;j<N;j++)
		{
			isZero=TRUE;
			for(i=0;i<M;i++)
			{
				if((S[i][j]!=0))
				{
					isZero=FALSE;
					break;
				}
			}

			if(isZero==TRUE)
			{
				C[numGr]++;
			}
		}

		numGr++;
		scanf("%d",&M);
		if(M==0)
			break;
		scanf("%d",&N);
	}

	for(i=0;i<numGr;i++)
	{
		printf("%d\n",C[i]);
	}

	return 0;
}