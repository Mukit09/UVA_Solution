#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

long x[1010],y[1010],i,j,k=1,u,v,n,ii,cnt,p[1010],mx,t,r[1010];
double road,rail;

struct ss
{
	long u,v;
	double cost;
}T[1000010];

bool cmp(ss aa, ss bb)
{
	if(aa.cost<bb.cost) return true;
	return false;
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
	else
		p[x]=y,r[y]++;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&mx);
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			scanf("%ld%ld",&x[i],&y[i]);
		}
		ii=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				T[ii].u=i;
				T[ii].v=j;
				T[ii].cost=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				ii++;
			}
		}
		sort(T,T+ii,cmp);
		cnt=1;
		road=rail=0;
		for(i=0;i<ii;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v&&T[i].cost<=mx)
			{
				road+=T[i].cost;
				link(u,v);
			}
			else if(u!=v&&T[i].cost>mx)
			{
				rail+=T[i].cost;
				i=i;
				link(u,v);
				cnt++;
			}
		}
		printf("Case #%ld: %ld %.0lf %.0lf\n",k++,cnt,road,rail);
	}
	return 0;
}
