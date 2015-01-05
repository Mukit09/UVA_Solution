#include<stdio.h>
#define max(a,b) (a>b ?a:b)
#define si 1010

long cost[si],wei[si],n,mx,dp[si][40];

long rec_re(long i,long w)
{
	long profit1,profit2;
	if(i>n)
		return 0;
	if(dp[i][w]!=-1)
		return dp[i][w];
	if(w+wei[i]<=mx)
		profit1=cost[i]+rec_re(i+1,w+wei[i]);
	else
		profit1=0;
	profit2=rec_re(i+1,w);
	dp[i][w]=max(profit1,profit2);
	return dp[i][w];
}

int main()
{
	long i,j,k,t,sum,g;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld%ld",&cost[i],&wei[i]);
		scanf("%ld",&g);
		sum=0;
		for(i=1;i<=g;i++)
		{
			scanf("%ld",&mx);
			for(j=1;j<=n;j++)
			{
				for(k=0;k<=mx;k++)
					dp[j][k]=-1;
			}
			sum+=rec_re(1,0);
		}
		printf("%ld\n",sum);
	}
	return 0;
}
