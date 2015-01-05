#include<stdio.h>
#include<algorithm>
using namespace std;

long p[20000000],r[20000000],x[15],y[15],cst[15];
long 

struct ss
{
	long u,v,cost;
}T[20000000];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

long find(long x)
{
	if(x==p[x])
		return x;
	else return p[x]=find(p[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else p[x]=y,r[y]++;
}

int main()
{
	long n,m,k,cost,min,i;
	while(scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			if(i!=n)
				scanf("%ld%ld%ld",&T[i-1].u,&T[i-1].v,&T[i-1].cost);
		}
		for(i=1;i<=k;i++)
			scanf("%ld%ld%ld",&x[i],&y[i],&cst[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld%ld",&u,&v,&cost);
			if()
		sort(T,T+n,cmp);
		printf("%ld\n",cost);
		min=cost;
		scanf("%ld",&k);
		for(i=0;i<k;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		scanf("%ld",&m);
		for(i=k;i<m;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		cost=calcu(m+k);
		if(min>cost)
			cost=min;
		printf("%ld\n",cost);
	}
	return 0;
}