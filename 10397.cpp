#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

long i,j,k,n,m,u,v,a,b,p[800],r[800],x[800],y[800];
double cost;

struct ss
{
	long u,v;
	double cost;
}T[600000];

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

int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			scanf("%ld%ld",&x[i],&y[i]);
		}
		scanf("%ld",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&u,&v);
			a=find(u);
			b=find(v);
			if(a!=b)
				link(a,b);
		}
		k=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				T[k].u=i;
				T[k].v=j;
				T[k++].cost=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		sort(T,T+k,cmp);
		cost=0;
		for(i=0;i<k;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				cost+=T[i].cost;
				link(u,v);
			}

		}
		printf("%.2lf\n",cost);
	}
	return 0;
}