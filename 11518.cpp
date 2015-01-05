#include<stdio.h>
#include<vector>

using namespace std;

vector<long>ve[10001];

long count;
long visit[100001];

void dfs(long node)
{
	long i,v;
	count++;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		v=ve[node][i];
		if(!visit[v])
			dfs(v);
	}
}

int main()
{
	long t,i,u,v,m,l,n;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&n,&m,&l);

		for(i=0;i<=n;i++)
		{
			visit[i]=0;
			ve[i].clear();
		}

		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
		}
		count=0;
		
		for(i=1;i<=l;i++)
		{
			scanf("%ld",&m);
			if(!visit[m])
				dfs(m);
		}
		printf("%ld\n",count);
	}
	return 0;
}