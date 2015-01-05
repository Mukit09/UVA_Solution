#include<stdio.h>
#include<vector>
#include<map>
#define si 101010
using namespace std;
vector<long>ve[si];
map<long,long>mp;

long visit[si],indeg[si],mx,fg,x=1,c0,c1,cnt;

void dfs(long node)
{
	long i,u;
	visit[node]=1;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(!visit[u])
		{
			visit[u]=1;
			cnt++;
			dfs(u);
		}
	}
}

int main()
{
	long u,v,i,j;
	while(~scanf("%ld%ld",&u,&v))
	{
		if(u<0&&v<0)
			break;
		c0=fg=mx=1,i=j=1;
		if(u!=0&&v!=0)
		{
			c0=c1=0;
			if(u==v)
				fg=0;
			if(mp[u]==0)
				mp[u]=i++;
			if(mp[v]==0)
				mp[v]=i++;
			u=mp[u];
			v=mp[v];
			indeg[v]++;
			if(mx<u)
				mx=u;
			if(mx<v)
				mx=v;	
			ve[u].push_back(v);
			while(~scanf("%ld%ld",&u,&v)&&(u||v))
			{
				if(u==v)
					fg=0;
				if(mp[u]==0)
					mp[u]=i++;
				if(mp[v]==0)
					mp[v]=i++;
				u=mp[u];
				v=mp[v];
				indeg[v]++;
				if(mx<u)
					mx=u;
				if(mx<v)
					mx=v;		
				ve[u].push_back(v);
			}
		
			for(i=1;i<=mx&&fg;i++)
			{
				if(indeg[i]==0)
				{
					j=i;
					c0++;
				}
				if(indeg[i]==1)
					c1++;
				if(c0>1||indeg[i]>1)
				{
					fg=0;
					break;
				}
			}
		}
		if(!fg||!c0)
			printf("Case %ld is not a tree.\n",x++);
		else
		{
			fg=cnt=1;
			dfs(j);
			if(cnt==mx)
				printf("Case %ld is a tree.\n",x++);
			else
				printf("Case %ld is not a tree.\n",x++);
		}
		for(i=1;i<=mx;i++)
		{
			ve[i].clear();
			visit[i]=indeg[i]=0;
		}
		mp.clear();
	}
	return 0;
}