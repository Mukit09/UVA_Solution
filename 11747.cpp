#include<stdio.h>
#include<algorithm>
using namespace std;

long i,j,n,e,a[1010],p[1010],r[1010],u,v,fg;

struct ss
{
	long u,v,cost;
}T[25010];

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
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		for(i=0;i<n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].u,&T[i].v,&T[i].cost);
		sort(T,T+e,cmp);
		fg=j=0;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
				link(u,v);
			else
			{
				fg=1;
				a[j++]=T[i].cost;
			}
		}
		if(!fg)
		{
			printf("forest\n");
			continue;
		}
		printf("%ld",a[0]);
		for(i=1;i<j;i++)
			printf(" %ld",a[i]);
		printf("\n");
	}
	return 0;
}
