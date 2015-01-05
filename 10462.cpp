#include<stdio.h>
#include<algorithm>
#define inf 999999999
using namespace std;

long j,k,x=1,cost,cnt,t,n,e,u,v,p[110],r[110],a[210];

struct ss
{
	long u,v,cost;
}T[210];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

void make_set()
{
	long i;
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		r[i]=1;
	}
}

long find(long x)
{
	if(p[x]==x)
		return x;
	else
		return p[x]=find(p[x]);
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
	long i,min;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		make_set();
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+e,cmp);
		j=0;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				a[j++]=i;
			}
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		printf("Case #%ld : ",x++);
		if(cnt!=1)
		{
			printf("No way\n");
			continue;
		}
		make_set();
		min=inf;
		for(i=0;i<j;i++)
		{
			cost=cnt=0;
			for(k=0;k<e;k++)
			{
				if(k==a[i])
					continue;
				u=find(T[k].u);
				v=find(T[k].v);
				if(u!=v)
				{
					link(u,v);
					cost+=T[k].cost;
				}
			}
			for(k=1;k<=n;k++)
			{
				u=find(k);
				if(u==k)
					cnt++;
			}
			make_set();
			if(cnt==1&&min>cost)
				min=cost;
		}
		if(inf>min)
			printf("%ld\n",min);
		else
			printf("No second way\n");
	}
	return 0;
}