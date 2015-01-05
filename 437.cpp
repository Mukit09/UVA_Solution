#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define si 10010
int in[4],dp[si],n;

struct ss
{
	int w,h,l;
}stru[si];

bool cmp(ss aa,ss bb)
{
	return aa.w*aa.l<bb.w*bb.l;
}

int rec(int u)
{
	if(u>n)
		return 0;
	int &ret=dp[u];
	if(ret!=-1)
		return ret;
	int v,mx=0,p;
	for(v=u+1;v<=n;v++)
	{
		if(stru[v].w>stru[u].w&&stru[v].l>stru[u].l)
		{
			p=rec(v);
			if(p>mx)
				mx=p;
		}
	}
	return ret=stru[u].h+mx;
}

int main()
{
	int i,j,x=1,mx,got;
	while(~scanf("%d",&n)&&n)
	{
		j=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&in[0],&in[1],&in[2]);
			sort(in,in+3);
			stru[j].w=in[1];
			stru[j].l=in[2];
			stru[j].h=in[0];
			dp[j]=-1;
			j++;
			stru[j].w=in[0];
			stru[j].l=in[2];
			stru[j].h=in[1];
			dp[j]=-1;
			j++;
			stru[j].w=in[0];
			stru[j].l=in[1];
			stru[j].h=in[2];
			dp[j]=-1;
			j++;
		}
		n=n*3;
		sort(stru,stru+n+1,cmp);
		mx=0;
		for(i=1;i<=n;i++)
		{
			if(dp[i]<0)
			{
				got=rec(i);
				if(got>mx)
					mx=got;
			}
		}
		printf("Case %d: maximum height = %d\n",x++,mx);
	}
	return 0;
}