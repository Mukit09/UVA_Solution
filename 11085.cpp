#include<stdio.h>
#include<stdlib.h>
#define inf 2147483647

long x[10],w[10],mn,cnt;

long place(long i,long k)
{
	long a,b,j;
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
				cnt=0;
				for(a=1;a<=8;a++)
				{
					if(w[a]!=x[a])
						cnt++;
				}
				if(mn>cnt)
					mn=cnt;
			}
			else 
				nqueen(k+1);
		}
	}
}

int main()
{
	long test=1;
	while(~scanf("%ld%ld%ld%ld%ld%ld%ld%ld",&w[1],&w[2],&w[3],&w[4],&w[5],&w[6],&w[7],&w[8]))
	{
		mn=inf;
		cnt=0;
		nqueen(1);
		printf("Case %ld: %ld\n",test++,mn);
	}
	return 0;
}