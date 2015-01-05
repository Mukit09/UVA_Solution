#include<stdio.h>
#include<algorithm>
using namespace std;

long u,v,i,k=1,t,n,m,cost,cnt,re,p[10010],r[10010];

struct ss
{
	long cost,u,v;
}T[100010];

bool cmp(ss aa,ss bb)
{
	if(aa.cost<bb.cost) return true;
	return false;
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
	{
		p[y]=x;
		r[x]++;
	}
	else
	{
		p[x]=y;
		r[y]++;
	}
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&n,&m,&cost);
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(i=0;i<m;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+m,cmp);
		cnt=re=0;
		for(i=0;i<m;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v&&T[i].cost<cost)
			{
				re+=T[i].cost;
				link(u,v);
			}
		}
		for(i=1;i<=n;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		re+=(cnt*cost);
		printf("Case #%ld: %ld %ld\n",k++,re,cnt);
	}
	return 0;
}
