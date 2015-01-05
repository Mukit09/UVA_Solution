#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

long i,j,k,u,v,n,t,p[110],r[110];
double x[110],y[110],cst;

struct ss
{
	long beg,end;
	double cost;
}T[11000];

bool cmp(ss aa,ss bb)
{
	return aa.cost<bb.cost;
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
			p[i]=i;
			r[i]=1;
		}
		k=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				T[k].beg=i;
				T[k].end=j;
				T[k++].cost=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
		sort(T,T+k,cmp);
		cst=0;
		for(i=0;i<k;i++)
		{
			u=find(T[i].beg);
			v=find(T[i].end);
			if(u!=v)
			{
				cst+=sqrt(T[i].cost);
				link(u,v);
			}
		}
		printf("%.2lf\n",cst);
		if(t)
			printf("\n");
	}
	return 0;
}