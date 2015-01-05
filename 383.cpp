#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
vector<long>ve[40];
map<string,long>mp;
queue<long>q;

char ch[10],source[10],dest[10],u[10],v[10],t;
long j,m,n,p,k,len,cost,a,b,cst[40],visit[40],x=1;

void bfs(long node)
{
	long i,c,d;	
	q.push(node);
	while(!q.empty())
	{
		c=q.front();
		visit[c]=1;
		for(i=0;i<ve[c].size();i++)
		{
			d=ve[c][i];
			if(visit[d]==0)
			{
				q.push(d);
				cst[d]=cst[c]+1;
				visit[d]=1;
			}
		}
		q.pop();
	}
}

int main()
{
	long i;
	scanf("%ld",&t);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	while(t--)
	{
		printf("DATA SET  %ld\n\n",x++);
		scanf("%ld%ld%ld",&m,&n,&p);
		for(i=1;i<=m;i++)
			scanf("%s",ch);
		j=1;
		for(i=1;i<=n;i++)
		{
			scanf("%s%s",u,v);
			if(mp[u]==0)
				mp[u]=j++;
			if(mp[v]==0)
				mp[v]=j++;
			ve[mp[u]].push_back(mp[v]);
			ve[mp[v]].push_back(mp[u]);
		}
		for(i=1;i<=p;i++)
		{
			for(k=1;k<j;k++)
				visit[k]=0;
				
			scanf("%ld%s%s",&len,source,dest);
			a=mp[source];
			b=mp[dest];
			cst[a]=0;
			if(a==0||b==0)
			{
				printf("NO SHIPMENT POSSIBLE\n");
				continue;
			}
			bfs(a);
			cost=len*cst[b]*100;
			printf("$%ld\n",cost);
		}
		printf("\n");
		mp.clear();
		for(i=1;i<j;i++)
			ve[i].clear();
	}
	printf("END OF OUTPUT\n");
	return 0;
}

