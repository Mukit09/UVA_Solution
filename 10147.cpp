#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

long i,j,k,t,n,m,p[1000],r[1000],x[1000],y[1000],u,v,fg,s1,s2;

struct ss
{
	long u,v;
	double cost;
}T[1010000];

struct re
{
	long u,v;
}TT[1010000];

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
	else
		p[x]=y,r[y]++;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			scanf("%ld%ld",&x[i],&y[i]);
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
		scanf("%ld",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&s1,&s2);
			u=find(s1);
			v=find(s2);
			if(u!=v)
				link(u,v);
		}
		fg=j=0;
		for(i=0;i<k;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				TT[j].u=T[i].u;
				TT[j++].v=T[i].v;
				fg=1;
			}
		}
		if(!fg)
			printf("No new highways need\n");
		else
		{
			for(i=0;i<j;i++)
				printf("%ld %ld\n",TT[i].u,TT[i].v);
		}
		if(t)
			printf("\n");
	}
	return 0;
}