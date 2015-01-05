#include<stdio.h>
#include<vector>
#define si 40
using namespace std;
vector<long>ve[si];

long visit[si],mx,a[si][si];

void dfs(long node,long cnt)
{
	long i,l=ve[node].size(),u;
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(a[node][u]==0)
		{
			if(cnt+1>mx)
				mx=cnt+1;
			a[node][u]=a[u][node]=1;
			dfs(u,cnt+1);
			a[node][u]=a[u][node]=0;
		}
	}
}

int main()
{
	long n,e,i,u,v,j,l;
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		for(i=0;i<n;i++)
		{
			visit[i]=0;
			for(j=0;j<n;j++)
				a[i][j]=0;
		}
		mx=0;
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		for(i=0;i<n;i++)
		{
			l=ve[i].size();
			for(j=0;j<l;j++)
			{
				u=ve[i][j];
				if(a[i][u]==0)
					dfs(i,0);
			}
		}
		printf("%ld\n",mx);
		for(i=0;i<n;i++)
			ve[i].clear();
	}
	return 0;
}