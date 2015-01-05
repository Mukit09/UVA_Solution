#include<stdio.h>

long p[5];
long r[5];
long re[5];

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

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

int main()
{
	long i,u,v,n,e,max,t,pu,pv;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&e);
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			re[i]=0;
		}

		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			pu=find(u);
			pv=find(v);
			if(pu!=pv)
				link(pu,pv);
		}
		for(i=1;i<=n;i++)
		{
			u=find(i);
			re[u]++;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			if(max<re[i])
				max=re[i];
		}
		printf("%ld\n",max);
	}
	return 0;
}