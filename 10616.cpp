#include<stdio.h>

long n,m,a[210],q,d,dp[210][15][25];

long rec(long i,long taken,long sm)
{
	if(i>n)
	{
		if(taken==m&&((sm%d)+d)%d==0)
			return 1;
		else
			return 0;
	}
	if(taken==m&&((sm%d)+d)%d==0)
		return 1;
	else if(taken==m)
		return 0;
	if(dp[i][taken][sm]!=-1)
		return dp[i][taken][sm];
	long p1,p2;
	p1=rec(i+1,taken+1,(sm+(a[i]%d+d)%d)%d);
	p2=rec(i+1,taken,sm);
	dp[i][taken][sm]=p1+p2;
	return dp[i][taken][sm];
}

int main()
{
	long i,x=1,re,j,k,l;
	while(~scanf("%ld%ld",&n,&q)&&(n||q))
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
	
		printf("SET %ld:\n",x++);
		for(i=1;i<=q;i++)
		{
			scanf("%ld%ld",&d,&m);
			for(j=1;j<=n;j++)
			{
				for(k=0;k<=m;k++)
					for(l=0;l<=d;l++)
						dp[j][k][l]=-1;
			}
			re=rec(1,0,0);
			printf("QUERY %ld: %ld\n",i,re);
		}
	}
	return 0;
}