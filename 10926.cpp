#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<long>ve[110];
queue<long>q;
long visit[110],cst;

void bfs(long u)
{
	long i,v,p;
	q.push(u);
	while(!q.empty())
	{
		v=q.front();
		visit[v]=1;
		cst++;
		for(i=0;i<ve[v].size();i++)
		{
			p=ve[v][i];
			if(visit[p]==0)
			{
				visit[p]=1;
				q.push(p);
			}
		}
		q.pop();
	}
}

int main()
{
	long i,j,n,v,mx,iden,t;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&t);
			for(j=1;j<=t;j++)
			{
				scanf("%ld",&v);
				ve[i].push_back(v);
			}
		}
		mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				visit[j]=0;
			cst=0;
			bfs(i);
			if(cst>mx)
			{
				mx=cst;
				iden=i;
			}
		}
		printf("%ld\n",iden);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}
