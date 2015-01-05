#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,long>mp;

char ch[15],ch1[15];
long i,cost,u,v,r[410],p[410],n,e,cnt;

struct ss
{
	long u,v,cost;
}T[80000];

bool cmp(ss aa,ss bb)
{
	if(aa.cost<bb.cost)
		return true;
	return false;
}

long find(long x)
{
	if(p[x]==x)
		return p[x];
	else
		return p[x]=find(p[x]);
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
	while(scanf("%ld%ld",&n,&e)&&(n||e))
	{
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			scanf("%s",ch);
			mp[ch]=i;
		}
		for(i=0;i<e;i++)
		{
			scanf("%s%s%ld",ch,ch1,&T[i].cost);
			T[i].u=mp[ch];
			T[i].v=mp[ch1];
		}
		sort(T,T+e,cmp);
		scanf("%s",ch);
		cost=0;
		for(i=0;i<e;i++)
		{
			u=find(T[i].u);
			v=find(T[i].v);
			if(u!=v)
			{
				link(u,v);
				cost+=T[i].cost;
			}
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			u=find(i);
			if(u==i)
				cnt++;
		}
		if(cnt==1)
			printf("%ld\n",cost);
		else
			printf("Impossible\n");
	}
	return 0;
}