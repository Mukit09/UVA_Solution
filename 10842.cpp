#include<stdio.h>
#include<algorithm>
using namespace std;

long p[110],r[110],i,cost,u,v,n,e,t,k=1;

struct ss
{
	long u,v,cost;
}T[10010];

bool cmp(ss aa,ss bb)
{
	return aa.cost>bb.cost;
}

long find(long x)
{
	if(p[x]==x)
		return x;
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
	long min;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=0;i<n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+e,cmp);
		min=99999;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				if(T[i].cost<min)
					min=T[i].cost;
			}
		}
		printf("Case #%ld: %ld\n",k++,min);
	}
	return 0;
}