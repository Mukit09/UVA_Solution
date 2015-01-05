#include<stdio.h>
#define size 50010

long p[size],r[size],a[size];

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

void parent(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	long i,j=1,u,v,n,m,count,pu,pv;
	while(~scanf("%ld%ld",&n,&m)&&(n||m))
	{
		for(i=1;i<=n;i++)
		{
			r[i]=1;
			p[i]=i;
			a[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&u,&v);
			pu=find(u);
			pv=find(v);
			if(pu!=pv)
				parent(pu,pv);
		}
		for(i=1;i<=n;i++)
		{
			u=find(i);
			a[u]++;
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0)
				count++;
		}
		printf("Case %ld: %ld\n",j++,count);
	}
	return 0;
}
