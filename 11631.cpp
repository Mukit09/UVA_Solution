#include<stdio.h>
#include<algorithm>
#define si 200010
using namespace std;

long n,e,i,u,v,re[si],p[si],r[si],cost;

struct ss
{
	long cst,beg,end;
}T[si];

bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
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
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		cost=0;
		for(i=0;i<n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(i=0;i<e;i++)
		{
			scanf("%ld%ld%ld",&T[i].beg,&T[i].end,&T[i].cst);
			cost+=T[i].cst;
		}
		sort(T,T+e,cmp);
		for(i=0;i<e;i++)
		{
			u=find(T[i].beg);
			v=find(T[i].end);
			if(u!=v)
			{
				link(u,v);
				cost-=T[i].cst;
			}
		}
		printf("%ld\n",cost);
	}
	return 0;
}
