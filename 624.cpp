#include<stdio.h>

long n,mx,weight[30],dp[130][50010],dir[130][50030];

long rec_kna(long i,long taken)
{
	long p1,p2;
	if(i>n)
		return 0;
	if(taken>mx)
		return 0;
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	if(taken+weight[i]<=mx)
		p1=weight[i]+rec_kna(i+1,taken+weight[i]);
	else
		p1=0;
	p2=rec_kna(i+1,taken);
	if(p1>p2)
	{
		dp[i][taken]=p1;
		dir[i][taken]=1;
	}
	else
	{
		dp[i][taken]=p2;
		dir[i][taken]=2;
	}
	return dp[i][taken];
}

void path_print(long i,long taken)
{
	if(i>n)
		return ;
	if(dir[i][taken]==-1)
		return ;
	if(dir[i][taken]==1)
	{
		printf("%ld ",weight[i]);
		path_print(i+1,taken+weight[i]);
	}
	else 
		path_print(i+1,taken);
}

int main()
{
	long sum,i,j;
	while(~scanf("%ld",&mx))
	{
		scanf("%ld",&n); 
		
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&weight[i]);
			for(j=0;j<=mx;j++)
				dir[i][j]=dp[i][j]=-1;
		}
		sum=rec_kna(1,0);
		path_print(1,0);
		printf("sum:%ld\n",sum);
	}
	return 0;
}