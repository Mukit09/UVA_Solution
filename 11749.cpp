#include<stdio.h>
#include<vector>
#define si 510

using namespace std;

vector<long>ve[si];
long a[si][si],n,e,u,v,cst,mx,cnt,visit[si];

void dfs(long node)
{
	visit[node]=1;
	long i,u;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(visit[u]==0&&a[node][u]==mx)
		{
			cnt++;
			dfs(u);	
		}
	}
}

int main()
{
	long max,i,j;
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		max=mx=-2147483648;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				a[i][j]=mx;
			visit[i]=0;
		}
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld%ld",&u,&v,&cst);
			ve[u].push_back(v);
			ve[v].push_back(u);
			if(a[u][v]<cst)
				a[u][v]=a[v][u]=cst;
			if(cst>mx)
				mx=cst;
		}
		for(i=1;i<=n;i++)
		{
			cnt=1;
			dfs(i);
			if(max<cnt)
				max=cnt;
		}
		printf("%ld\n",max);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}
