#include<stdio.h>
#include<vector>
#include<queue>
#define si 10
#define min -2147483647 
using namespace std;

vector<long>ve[si];
queue<long>q;
long d[si],mx,cost,source,t,n,p,r,cnt[si];

void bfs(long node)
{
	long i,u,v,l;
	q.push(node);
	d[node]=0;
	while(!q.empty())
	{
		u=q.front();
		l=ve[u].size();
		for(i=0;i<l;i++)
		{
			v=ve[u][i];
			if(d[v]==min)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
		q.pop();
	}
}

int main()
{
	long i,j;
	while(~scanf("%ld",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&p);
			for(j=0;j<p;j++)
			{
				scanf("%ld",&r);
				ve[i].push_back(r);
			}
		}
		scanf("%ld",&t);
		while(t--)
		{
			for(i=0;i<n;i++)
			{
				d[i]=min;
				cnt[i]=0;
			}
			scanf("%ld",&source);
			if(ve[source].size()==0)
				printf("0\n");
			else
			{
				bfs(source);
				mx=min;
				for(i=0;i<n;i++)
				{
					if(d[i]!=min)
						cnt[d[i]]++;
				}
				for(i=0;i<n;i++)
				{
					if(mx<cnt[i])
					{
						mx=cnt[i];
						j=i;
					}
				}
				printf("%ld %ld\n",mx,j);
			}
		}
		for(i=0;i<n;i++)
			ve[i].clear();
	}
	return 0;
}