#include<stdio.h>
#include<algorithm>
#define inf 999999999
using namespace std;

long t,cst,cst1,cnt,r[110],p[110],indx[5010],n,e,u,v,x;

struct ss
{
	long u,v,cost;
}T[5000];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
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

void make_set()
{
	long i;
	for(i=1;i<=n;i++)
	{
		r[i]=1;
		p[i]=i;
	}
}

int main()
{
	long i,j,min;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		make_set();
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+e,cmp);
		x=cst=0;
		min=inf;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				cst+=T[i].cost;
				indx[x++]=i;
			}
		}
		make_set();
		for(i=0;i<x;i++)
		{
			cst1=0;
			for(j=0;j<e;j++)
			{
				if(j==indx[i])
					continue;
				u=find(T[j].u);
				v=find(T[j].v);
				if(u!=v)
				{
					cst1+=T[j].cost;
					link(u,v);
				}
			}
			cnt=0;
			for(j=1;j<=n;j++)
			{
				u=find(j);
				if(u==j)
					cnt++;
			}
			make_set();
			if(min>cst1&&cnt==1)
				min=cst1;
		}
		if(min==inf)
			min=cst;
		printf("%ld %ld\n",cst,min);
	}
	return 0;
}