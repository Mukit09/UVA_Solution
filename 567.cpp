#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<long>ve[30];
queue<long>q;

long visit[30],cst[30],p,n,k=1;

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
				cst[v]=cst[u]+1;
				q.push(v);
				visit[v]=1;
			}
		}
		q.pop();
	}
}

int main()
{
	long i=1,j,u,v;
	while(~scanf("%ld",&n))
	{
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&p);
			ve[i].push_back(p);
			ve[p].push_back(i);
		}
		for(i=2;i<=19;i++)
		{
			scanf("%ld",&n);
			for(j=1;j<=n;j++)
			{
				scanf("%ld",&p);
				ve[i].push_back(p);
				ve[p].push_back(i);
			}
		}
		scanf("%ld",&n);
		printf("Test Set #%ld\n",k++);
		while(n--)
		{
			for(i=1;i<=20;i++)
				visit[i]=0,cst[i]=0;
			scanf("%ld%ld",&u,&v);
			cst[u]=0;
			bfs(u);
			printf("%2ld to %2ld: %ld\n",u,v,cst[v]);
		}
		for(i=1;i<=20;i++)
			ve[i].clear();
		i=1;
		printf("\n");
	}
	return 0;
}