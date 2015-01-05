#include<stdio.h>
#include<vector>
using namespace std;

vector<long>ve[30010];
long visit[30010],e,u,g,v,n,cnt;

void dfs(long node)
{
	long i,u;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			cnt++;
			dfs(u);
		}
	}
}

int main()
{
	long i,j;
	while(~scanf("%ld%ld",&n,&g)&&(n||g))
	{
		for(i=0;i<n;i++)
		{
			visit[i]=0;
			ve[i].clear();
		}
		for(i=1;i<=g;i++)
		{
			scanf("%ld",&e);
			scanf("%ld",&u);
			for(j=1;j<e;j++)
			{
				scanf("%ld",&v);
				ve[u].push_back(v);
				ve[v].push_back(u);
			}
		}
		cnt=1;
		dfs(0);
		printf("%ld\n",cnt);
	}
	return 0;
}
