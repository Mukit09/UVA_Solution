#include<stdio.h>
#include<vector>
#define si 210
using namespace std;
vector<long>ve[si];
long visit[si],c1,c2,chk[si],fg;
long min(long a,long b)
{
	if(a<b) return a;
	return b;
}

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
			if(chk[node]==1)
				chk[v]=2,c2++;
			else if(chk[node]==2)
				chk[v]=1,c1++;
			visit[v]=1;
			dfs(v);
		}
	}
}

int main()
{
	long t,i,n,e,sm,u,v;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=0;i<n;i++)
			visit[i]=chk[i]=0;
		for(i=0;i<e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		sm=0,fg=1;
		for(i=0;i<n;i++)
		{
			if(visit[i]==0)
			{
				chk[i]=1;
				if(ve[i].size())
				{
					c1=1,c2=0;
					dfs(i);
					sm+=min(c1,c2);
				}
				else
					sm++;
			}
		}
		if(fg)
			printf("%ld\n",sm);
		else
			printf("-1\n");
		for(i=0;i<n;i++)
			ve[i].clear();
	}
	return 0;
}