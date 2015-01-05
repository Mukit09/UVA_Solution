#include<stdio.h>
#include<vector>
#define si 310
using namespace std;
vector<long>ve[si];

long chk[si],visit[si],fg;

void dfs(long node)
{
	long u,i;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(chk[node]==chk[u])
			fg=0;
		if(visit[u]==0)
		{
			if(chk[node]==1)
				chk[u]=2;
			else if(chk[node]==2)
				chk[u]=1;
			visit[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long n,i,u,v;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
			visit[i]=chk[i]=0;

		while(~scanf("%ld%ld",&u,&v)&&(u||v))
		{
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		fg=1;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0&&fg)
			{
				chk[i]=1;
				dfs(i);
			}
		}
		if(fg)
			printf("YES\n");
		else
			printf("NO\n");
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}