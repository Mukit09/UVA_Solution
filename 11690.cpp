/*
// By DFS,but after got accepted I did it with Union Find,which is given below
#include<stdio.h>
#include<math.h>
#include<vector>
#define si 10010
using namespace std;
vector<long>ve[si];

long cst[si],fg,visit[si],now;

void dfs(long node)
{
	long i,u,l;
	visit[node]=1;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			cst[now]+=cst[u];
			dfs(u);
		}
	}
}

int main()
{
	long t,i,u,v,n,m;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&cst[i]);
			visit[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		fg=1;
		for(i=0;i<n;i++)
		{
			if(!visit[i])
			{
				now=i;
				dfs(i);
				if(cst[i])
				{
					fg=0;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
			ve[i].clear();
		if(fg)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
		*/

#include<stdio.h>
#define si 10010

int cst[si],fg,p[si],r[si],res[si],store[si];

void link(int x,int y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int find(int x)
{
	if(x==p[x])
		return x;
	else
		return p[x]=find(p[x]);
}

int main()
{
	int t,i,u,v,n,m,pu,pv,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&cst[i]);
			res[i]=0;
			p[i]=i;
			r[i]=1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			pu=find(u);
			pv=find(v);
			if(pu!=pv)
				link(pu,pv);
		}
		fg=1;
		j=0;
		for(i=0;i<n;i++)
		{
			pu=find(i);
			res[pu]+=cst[i];
			store[j++]=pu;
		}
		for(i=0;i<j;i++)
		{
			if(res[i])
			{
				fg=0;
				break;
			}
		}
		if(fg)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
		