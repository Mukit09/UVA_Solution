#include<stdio.h>
#include<vector>
using namespace std;
vector<long>ve[200100];
long color[210],visit[210],fg;

void dfs(long node)
{
	long i,u;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(color[node]==color[u])
			fg=0;
		if(visit[u]==0)
		{
			visit[u]=1;
			if(color[node]==1)
				color[u]=2;
			else if(color[node]==2)
				color[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long n,e,i,u,v;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=0;i<n;i++)
			color[i]=visit[i]=0;
		scanf("%ld",&e);
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		color[0]=1;
		fg=1;
		dfs(0);
		if(fg)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		for(i=0;i<n;i++)
			ve[i].clear();
	}
	return 0;
}