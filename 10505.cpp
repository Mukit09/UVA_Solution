#include<stdio.h>
#include<vector>
#define si 215
#define max(a,b) (a>b?a:b)
using namespace std;
vector<long>ve[si];
long chk[si],visit[si],fg,c1,c2,n;

void dfs(long node)
{
	long i,v;
	visit[node]=1;

	for(i=0;i<ve[node].size();i++)
	{
		v=ve[node][i];
		if(chk[node]==chk[v])
			fg=0;
		if(visit[v]==0)
		{
			visit[v]=1;
			if(chk[node]==1)
				chk[v]=2,c2++;
			else if(chk[node]==2)
				chk[v]=1,c1++;
			dfs(v);
		}
	}
}

int main()
{
	long t,i,p,v,sm;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);

		for(i=1;i<=n;i++)
		{
			visit[i]=chk[i]=0;
			scanf("%ld",&p);
			while(p--)
			{
				scanf("%ld",&v);
				if(v<=n)
				{
					ve[i].push_back(v);
					ve[v].push_back(i);
				}
			}
		}
		sm=0;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				if(ve[i].size())
				{
					c1=1,c2=0,fg=1;
					chk[i]=1;
					dfs(i);
					if(fg)
						sm+=max(c1,c2);
				}
				else 
					sm++;
			}
		}
		printf("%ld\n",sm);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}