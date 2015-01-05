#include<stdio.h>
#include<stdlib.h>

long x[10],y1,x1,test;

long place(long i,long k)
{
	long j,a,b;
	for(j=1;j<k;j++)
	{
		a=abs(x[j]-i);
		b=abs(j-k);
		if(a==b||x[j]==i)
			return 0;
	}
	return 1;
}

void nqueen(long k)
{
	long i,a;
	for(i=1;i<=8;i++)
	{
		if(place(i,k))
		{
			x[k]=i;
			if(k==8)
			{
				if(x[y1]==x1)
				{
					printf("%2ld     ",test++);
					for(a=1;a<=8;a++)
						printf(" %ld",x[a]);
					printf("\n");
				}
			}
			else
				nqueen(k+1);
		}
	}
}

int main()
{
	long t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&x1,&y1);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		test=1;
		nqueen(1);
		if(t)
			printf("\n");
	}
	return 0;
}