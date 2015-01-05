#include<stdio.h>

long weight[110],mx,n,dp[110][50010];

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

long rec(long i,long w)
{
	long p1,p2;
	if(i>n)
		return 0;
	if(dp[i][w]!=-1)
		return dp[i][w];
	if(w+weight[i]<=mx)
		p1=weight[i]+rec(i+1,w+weight[i]);
	else
		p1=0;
	p2=rec(i+1,w);
	dp[i][w]=max(p1,p2);
	return dp[i][w];
}

int main()
{
	long t,sum,i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&weight[i]);
			sum+=weight[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=sum;j++)
				dp[i][j]=-1;
		}
		mx=sum/2;
		n=2*rec(1,0);
		sum=sum-n;
		printf("%ld\n",sum);
	}
	return 0;
}
