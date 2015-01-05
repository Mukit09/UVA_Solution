#include<stdio.h>
#include<vector>
#define si 1010
#define min(a,b) (a<b?a:b)
using namespace std;
vector<long>ve[si];

long dp[si][5],par[si];

long rec(long node,long fg)
{
	if(ve[node].size()==0)
		return 1;
	if(dp[node][fg]!=-1)
		return dp[node][fg];
	long i,u,sm=0;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(u!=par[node])
		{
			par[u]=node;
			if(fg)
				sm+=min(rec(u,1),rec(u,0));
			else
				sm+=rec(u,1);
		}
	}
	dp[node][fg]=sm+fg;
	return dp[node][fg];
}

int main()
{
	long n,i,p,u,sm,j;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&p);
			for(j=1;j<=p;j++)
			{
				scanf("%ld",&u);
				ve[i].push_back(u);
			}
			dp[i][1]=dp[i][0]=-1;
			par[i]=-1;
		}
		sm=min(rec(1,1),rec(1,0));
		printf("%ld\n",sm);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}