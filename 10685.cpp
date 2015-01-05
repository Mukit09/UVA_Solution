#include<stdio.h>
#include<map>
#include<string>
#include<string.h>

using namespace std;

map<string,long>mp;

char ch[5010][40];
char u[40],v[40];
long r[5010];
long p[5010];
long a[5010];

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
	long n,m,i,max,pu,pv;
	while(scanf("%ld%ld",&n,&m)&&(n||m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch[i]);
			mp[ch[i]]=i;
			r[i]=1;
			p[i]=i;
			a[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s%s",u,v);
			pu=find(mp[u]);
			pv=find(mp[v]);
			if(pu!=pv)
				parent(pu,pv);
		}
		for(i=1;i<=n;i++)
		{
			pu=find(i);
			a[pu]++;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			if(max<a[i])
				max=a[i];
			
		}
		printf("%ld\n",max);
	}
	return 0;
}