#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector<long>ve[50];
queue<long>q;
map<long,long>mp;

long visit[50],cst[50],e,u,v,source,cost,x=1;

void bfs(long node)
{
	long i,u,v;
	q.push(node);
	while(!q.empty())
	{
		v=q.front();
		visit[v]=1;
		for(i=0;i<ve[v].size();i++)
		{
			u=ve[v][i];
			if(visit[u]==0)
			{
				q.push(u);
				visit[u]=1;
				cst[u]=cst[v]+1;
			}
		}
		q.pop();
	}
}

int main()
{
	long i,j,k;
	while(~scanf("%ld",&e)&&e)
	{
		k=1;
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			if(mp[u]==0)
				mp[u]=k++;
			if(mp[v]==0)
				mp[v]=k++;
			ve[mp[u]].push_back(mp[v]);
			ve[mp[v]].push_back(mp[u]);

		}
		while(~scanf("%ld%ld",&source,&cost)&&(source||cost))
		{
			for(i=1;i<k;i++)
			{
				visit[i]=0;
				cst[i]=999999999;
			}
			u=mp[source];
			if(u==0)
			{
				printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",x++,k-1,source,cost);
				continue;
			}
			cst[u]=0;
			bfs(u);
			j=0;
			for(i=1;i<k;i++)
			{
				if(cst[i]>cost)
					j++;
			}
			printf("Case %ld: %ld nodes not reachable from node %ld with TTL = %ld.\n",x++,j,source,cost);

		}
		mp.clear();
		for(i=1;i<k;i++)
			ve[i].clear();

	}
	return 0;
}
