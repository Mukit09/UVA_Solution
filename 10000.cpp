#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<long>ve[110];
queue<long>q;

long d[110];
long n,s,a,u,v,end,mx;

void bfs(long x)
{
	long y,b;
	q.push(x);
	while(!q.empty())
	{
		a=q.front();
		for(y=0;y<ve[a].size();y++)
		{
			b=ve[a][y];
			if(d[b]<=d[a])
			{
				d[b]=d[a]+1;
				q.push(b);
			}
		}
		q.pop();
	}
}

int main()
{
	long i,k=1;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			d[i]=0;
			ve[i].clear();
		}

		scanf("%ld",&s);
		end=s;
		while(scanf("%ld%ld",&u,&v)&&(u||v))
			ve[u].push_back(v);
	
		bfs(s);
		i=s;
		mx=0;
		for(i=1;i<=n;i++)
		{
			if(d[i]>mx)
			{
				mx=d[i];
				end=i;
			}
		}
		printf("Case %ld: The longest path from %ld has length %ld, finishing at %ld.\n\n",k++,s,mx,end);
	}
	return 0;
}