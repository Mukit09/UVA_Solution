#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#define inf 99999999
#define si 1010
using namespace std;

vector<long>ve[si];
queue<long>q;
map<string,long>mp;

char u[10],v[10],ch[si][10],st[si][10],re1[si][10],re2[si][10];
long n,e,source,dest,visit[si],cst[si],p[si],flag;

void bfs(long node)
{
	long c,d,i;
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
				p[d]=c;
			}
		}
		q.pop();
	}
}

int main()
{
	long i,j,fg=0;
	while(~scanf("%ld",&e))
	{
		if(fg)
			printf("\n");
		fg=1;
		flag=0;
		n=1;
		for(i=1;i<=e;i++)
		{
			scanf("%s%s",u,v);
			if(mp[u]==0)
			{
				strcpy(ch[n],u);
				mp[u]=n++;
			}
			if(mp[v]==0)
			{
				strcpy(ch[n],v);
				mp[v]=n++;
			}
			ve[mp[u]].push_back(mp[v]);
			ve[mp[v]].push_back(mp[u]);
		}
		for(i=1;i<n;i++)
		{
			visit[i]=0;
			p[i]=i;
			cst[i]=inf;
		}
		scanf("%s%s",&u,&v);
		source=mp[u];
		dest=mp[v];
		if(strcmp(u,v)==0)
		{
			printf("%s %s\n",u,v);
			continue;
		}
		cst[source]=0;
		bfs(source);
		
		if(source==0||dest==0||cst[dest]==inf)
			printf("No route\n");

		else
		{
			i=1;
			while(p[dest]!=dest)
			{
				strcpy(re1[i],ch[p[dest]]);
				strcpy(re2[i],ch[dest]);
				i++;		
				dest=p[dest];
			}
			for(j=i-1;j>=1;j--)
				printf("%s %s\n",re1[j],re2[j]);
		}
		for(i=1;i<=n;i++)
			ve[i].clear();
		mp.clear();
	}
	return 0;
}