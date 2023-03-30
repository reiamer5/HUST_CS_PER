#include<stdio.h>
#include<stdlib.h>

long main()
{
	long *data1;
	long *data2;

	long n1=0,n2=0,mid=0;

	long i=0,j=0,k=0;

	long midN=0;
	
	while(scanf("%d",&n1)!=EOF)
	{
		data1=(long *) malloc (sizeof(long)*n1);
		for(i=0;i<n1;i++)
		{
			scanf("%d",&data1[i]);
		}

		scanf("%d",&n2);
		data2=(long *) malloc (sizeof(long)*n2);
		for(i=0;i<n2;i++)
		{
			scanf("%d",&data2[i]);
		}
	
		//------------------------------------------------------------
		mid=(n1+n2)%2==0?(n1+n2)/2:(n1+n2)/2+1;
		//------------------------------------------------------------
		
		i=j=k=0;

		while(k<mid &&i<n1 && j<n2)
		{
			if(data1[i]<data2[j])
			{	
				midN=data1[i];
				i++;
			}
			else if(data1[i]>=data2[j] && j<n2)
			{	
				midN=data2[j];
				j++;
			}
			k++;
		}
		
		if(k<mid)
		{
			long *p=data2+j-1;//¼õÒ»
			if(i<n1)
				p=data1+i-1;//¼õÒ»
			while(k<mid)
			{
				p++;
				k++;
			}
			
			midN=*p;
		}
		printf("%d\n",midN);
		free(data1);
		free(data2);
	}
	return 0;

}