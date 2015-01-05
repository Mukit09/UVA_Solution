#include<stdio.h>
#include<vector>
#include<queue>
#define si 1010
using namespace std;

vector<long>ve[si];
queue<long>q;
long visit[si],cst[si],n,e,t;

void bfs(long node)
{
	long i,u,v;
	visit[node]=1;
	q.push(node);
	while(!q.empty())
	{
		u=q.front();
		for(i=0;i<ve[u].size();i++)
		{
			v=ve[u][i];
			if(visit[v]==0)
			{
				visit[v]=1;
				q.push(v);
				cst[v]=cst[u]+1;
			}
		}
		q.pop();
	}
}

int main()
{
	long i,u,v;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		cst[0]=0;
		for(i=0;i<n;i++)
			visit[i]=0;
		bfs(0);
		for(i=1;i<n;i++)
		{
			ve[i].clear();
			printf("%ld\n",cst[i]);
		}
		ve[0].clear();
		if(t)
			printf("\n");
	}
	return 0;
}
