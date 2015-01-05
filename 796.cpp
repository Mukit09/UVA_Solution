#include<stdio.h>
#include<vector>
#include<algorithm>
#define min(a,b) (a<b ?a:b)
#define si 1010
using namespace std;
vector<long>ve[si];
char ch[30];
long visit[si],num,df[si],k;

struct ss
{
	long x,y;
}stru[si];

bool cmp(ss aa,ss bb)
{
	if(aa.x==bb.x)
		return aa.y<bb.y;
	return aa.x<bb.x;
}

long dfs(long node,long p)
{
	visit[node]=1;
	df[node]=num++;
	long l=num,i,ll=ve[node].size(),u,rec;
	for(i=0;i<ll;i++)
	{
		u=ve[node][i];
		if(visit[u]==0&&u!=p)
		{
			visit[u]=1;
			rec=dfs(u,node);
			if(rec>df[node])
			{
				if(node<u)
				{
					stru[k].x=node;
					stru[k].y=u;
				}
				else
				{
					stru[k].x=u;
					stru[k].y=node;
				}
				k++;
			}
			l=min(l,rec);
		}
		else if(u!=p)
			l=min(l,df[u]);
	}
	return l;
}

int main()
{
	long i,j,n,e,u,v;
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld%s",&u,ch);
			e=0;
			for(j=0;ch[j];j++)
			{
				if(ch[j]>=48&&ch[j]<=57)
					e=e*10+ch[j]-48;
			}
			for(j=1;j<=e;j++)
			{
				scanf("%ld",&v);
				ve[u].push_back(v);
				ve[v].push_back(u);
			}
		}
		k=0;
		num=1;
		for(i=0;i<n;i++)
		{
			if(visit[i]==0)
				dfs(i,-1);
		}
		sort(stru,stru+k,cmp);
		printf("%ld critical links\n",k);
		for(i=0;i<k;i++)
			printf("%ld - %ld\n",stru[i].x,stru[i].y);
		printf("\n");
		for(i=0;i<n;i++)
		{
			ve[i].clear();
			visit[i]=0;
		}
	}
	return 0;
}