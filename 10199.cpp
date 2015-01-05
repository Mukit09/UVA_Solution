#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<string>
#define min(a,b) (a<b ?a:b)
#define si 110
using namespace std;
map<string,long>mp;
vector<long>ve[si];
char ch[si][40],ch1[40],ch2[40];

long df[si],visit[si],cnt[si],num,res[si],par[si],pa;

struct ss
{
	string st;
}stru[si];

bool cmp(ss aa,ss bb)
{
	return aa.st<bb.st;
}

long dfs(long node,long p)
{
	df[node]=num++;
	visit[node]=1;
	long l=num,i,ll=ve[node].size(),u,rec;
	for(i=0;i<ll;i++)
	{
		u=ve[node][i];
		if(visit[u]==0&u!=p)
		{
			visit[u]=1;
			rec=dfs(u,node);
			if(node==pa)
				cnt[node]++;
			if(rec>=df[node])
				res[node]++;
			l=min(l,rec);
		}
		else if(u!=p)
			l=min(l,df[u]);
	}
	visit[node]=2;
	return l;
}

int main()
{
	long n,i,e,x=1,u,v,j,fg=0,c;
	while(~scanf("%ld",&n)&&n)
	{
		if(fg)
			printf("\n");
		fg=1;
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch[i]);
			mp[ch[i]]=i;
		}
		scanf("%ld",&e);
		while(e--)
		{
			scanf("%s%s",ch1,ch2);
			u=mp[ch1];
			v=mp[ch2];
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		num=1;
		c=0;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				pa=i;
				par[i]=1;
				dfs(i,-1);
			}
		}
		j=0;
		for(i=1;i<=n;i++)
		{
			if(res[i])
			{
				if(par[i]&&cnt[i]>1)
				{
					c++;
					stru[j++].st=ch[i];
				}
				else if(par[i]!=1)
				{
					c++;
					stru[j++].st=ch[i];
				}
			}
			ve[i].clear();
			res[i]=visit[i]=cnt[i]=par[i]=0;
		}
		sort(stru,stru+j,cmp);
		printf("City map #%ld: %ld camera(s) found\n",x++,c);
		for(i=0;i<j;i++)
			cout<<stru[i].st<<endl;
	}
	return 0;
}