#include<stdio.h>
#include<vector>
#include<queue>
#define inf 2147483646
#define si 30
using namespace std;

vector<long>ve[si];
queue<long>q;

char ch1[5],ch2[5];
long p[si],adj[si][si],visit[si],cst[si],n,e,t,cost,ans[si];

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
			if(visit[v]==0||cst[v]>cst[u]+adj[u][v])
			{
				if(cst[v]>cst[u]+adj[u][v])
				{
					p[v]=u;
					cst[v]=cst[u]+adj[u][v];
				}
				q.push(v);
				visit[v]=1;
			}
		}
		q.pop();
	}
}
int main()
{
	long i,u,v,j;
	while(~scanf("%ld%ld",&n,&e))
	{
		for(i=1;i<=e;i++)
		{
			scanf("%s%s%ld",&ch1,&ch2,&cost);
			u=ch1[0]-64;
			v=ch2[0]-64;
			ve[u].push_back(v);
			ve[v].push_back(u);
			adj[u][v]=adj[v][u]=cost;
		}
		scanf("%ld",&t);
		while(t--)
		{
			for(i=1;i<=n;i++)
			{
				visit[i]=0;
				cst[i]=inf;
				p[i]=-1;
			}
			scanf("%s%s",ch1,ch2);
			u=ch1[0]-64;
			v=ch2[0]-64;
			cst[u]=0;
			p[u]=u;
			bfs(u);
			i=1;
			while(v!=p[v])
			{
				ans[i]=v;
				v=p[v];
				i++;
			}
			printf("%c",u+64);
			for(j=i-1;j>=1;j--)
				printf(" %c",ans[j]+64);
			printf("\n");
		}
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}