#include<stdio.h>
#include<vector>

using namespace std;

vector<long>v[500];

long in[500],visit[500],count;

void dfs(long node)
{
	long i,u;
	
	for(i=0;i<v[node].size();i++)
	{
		u=v[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			count++;
			dfs(v[node][i]);
		}
	}
}


int main()
{
	long n,i,j,t;
	while(scanf("%ld",&n)&&n)
	{
		while(scanf("%ld",&i)&&i)
		{
			while(scanf("%ld",&j)&&j)
				v[i].push_back(j);
			count=0;
		}
		scanf("%ld",&t);
		for(i=1;i<=t;i++)
			scanf("%ld",&in[i]);

		for(j=1;j<=t;j++)
		{
			count=0;
			dfs(in[j]);
			printf("%ld",n-count);
			for(i=1;i<=n;i++)
			{
				if(visit[i]==0)
					printf(" %ld",i);
				visit[i]=0;
			}
			printf("\n");
		}
		for(i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}