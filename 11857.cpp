#include<stdio.h>
#include<algorithm>
using namespace std;

long n,m,u,v,i,r[1000010],p[1000010],cnt,mx;

struct ss
{
	long u,v,cost;
}T[1000010];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

long find(long x)
{
	if(p[x]==x) return x;
	else return p[x]=find(p[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y]) 
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	while(~scanf("%ld%ld",&n,&m)&&(n||m))
	{
		for(i=0;i<n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(i=0;i<m;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+m,cmp);
		cnt=mx=0;
		for(i=0;i<m;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				if(mx<T[i].cost)
					mx=T[i].cost;
			}
		}
		for(i=0;i<n;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		if(cnt==1)
			printf("%ld\n",mx);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
		