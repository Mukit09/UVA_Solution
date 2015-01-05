#include<stdio.h>
#include<algorithm>
using namespace std;

long n,dp[1010],dir[1010];

struct ss
{
	long w,iq,no;
}T[1010];

bool cmp(ss aa,ss bb)
{
	if(aa.iq==bb.iq)
		return aa.w<bb.w;
	return aa.iq>bb.iq;
}

long longest(long u)
{
	if(u==n)
		return 0;
	if(dp[u]!=-1)
		return dp[u];
	long v,mx=0,p;
	for(v=u+1;v<n;v++)
	{
		if(T[v].w>T[u].w)
		{
			p=longest(v);
			if(mx<p)
			{
				dir[u]=v;
				mx=p;
			}
		}
	}
	dp[u]=mx+1;
	return dp[u];
}

void path_print(long start)
{
	while(1)
	{
		printf("%ld\n",T[start].no);
		if(dir[start]==-1)
			break;
		start=dir[start];
	}
}

int main()
{
	long i,mx=0,p,start;
	i=0;
	while(~scanf("%ld%ld",&T[i].w,&T[i].iq))
	{
		dir[i]=dp[i]=-1;
		T[i].no=i+1;
		i++;
	}
	n=i+1;
	sort(T,T+i,cmp);
	for(i=0;i<n;i++)
	{
		p=longest(i);
		if(mx<p)
		{
			start=i;
			mx=p;
		}
	}
	printf("%ld\n",mx);
	path_print(start);
	return 0;
}
