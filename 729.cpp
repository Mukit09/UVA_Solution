#include<stdio.h>
#include<string.h>

long taken[20],n,h;

void rec(long l,long j)
{
	long i;
	if(l==n-h)
	{
		for(i=1;i<=n;i++)
			printf("%ld",taken[i]);
		printf("\n");
		return ;
	}
	for(i=j+1;i<=n;i++)
	{
		if(taken[i]==1)
		{
			taken[i]=0;
			rec(l+1,i);
			taken[i]=1;
		}
	}
}

int main()
{
	long t,i;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&h);
		for(i=1;i<=n;i++)
			taken[i]=1;
		rec(0,0);
		if(t)
			printf("\n");
	}
	return 0;
}
		