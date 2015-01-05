#include<stdio.h>
#include<map>
#include<string>
#include<string.h>

using namespace std;

map<string,long>mp;

char u[30],v[30];
long r[100010];
long p[100010],re;

long find(long x)
{
	if(p[x]==x)
		return x;
	else
		return p[x]=find(p[x]);
}

void parent(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]+=r[y],re=r[x];
	else
		p[x]=y,r[y]+=r[x],re=r[y];
}

int main()
{
	long i,t,n,j,pu,pv;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			r[i]=1;
			p[i]=i;
		}
		j=1;
		while(n--)
		{
			scanf("%s%s",u,v);
			if(mp[u]==0)
				mp[u]=j++;

			if(mp[v]==0)
				mp[v]=j++;
			
			pu=find(mp[u]);
			pv=find(mp[v]);
			
			if(pu!=pv)
				parent(pu,pv);
			else 
				re=r[pu];
			
			printf("%ld\n",re);
		}
		mp.clear();
	}
	return 0;
}