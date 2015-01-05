#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<long>ve[310];
queue<long>q;
long p[310],visit[310],t,n,r,a[310],fg;
char c;

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
				q.push(v);
				visit[v]=1;
				p[v]=u;
			}
		}
		q.pop();
	}
}

int main()
{
	long i,u,v,j;
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&r);
			c=getchar();
			c=getchar();
			while(c!='\n')
			{
				r=0;
				while(c>=48&&c<=57)
				{
					r=r*10+(c-48);
					c=getchar();
				}
				ve[i].push_back(r);
				if(c=='\n')
					break;
				c=getchar();
			}
		}
		scanf("%ld",&t);
		printf("-----\n");
		while(t--)
		{
			for(i=1;i<=n;i++)
				visit[i]=0,p[i]=-1;
			scanf("%ld%ld",&u,&v);
			p[u]=u;
			bfs(u);
			i=1;
			fg=0;
			while(v!=p[v])
			{
				if(p[v]==-1)
				{
					fg=1;
					break;
				}
				a[i]=v;
				v=p[v];
				i++;
			}
			if(fg)
				printf("connection impossible\n");
			else
			{
				printf("%ld",u);
				for(j=i-1;j>=1;j--)
					printf(" %ld",a[j]);
				printf("\n");
			}
		}
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}