#include<stdio.h>
#include<vector>
#include<string.h>
#define inf 110000
#define si 10010
using namespace std;

vector<long>ve[si],ve_w[si];
long visit[si],cst[si],n,mx,ii,w;
char ch[si];

void dfs(long node)
{
	visit[node]=1;
	long i,u,l,ww;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			ww=ve_w[node][i];
			cst[u]=cst[node]+ww;
			if(mx<cst[u])
			{
				mx=cst[u];
				ii=u;
			}
			dfs(u);
		}
	}
}

int main()
{
	long st=inf,end=1,u,v,j,i=1;
	while(gets(ch))
	{
		if(strcmp(ch,"")!=0)
		{
			sscanf(ch,"%ld%ld%ld",&u,&v,&w);
			if(u>end)
				end=u;
			if(v>end)
				end=v;
			if(u<st)
				st=u;
			if(v<st)
				st=v;
			ve[u].push_back(v);
			ve[v].push_back(u);
			ve_w[u].push_back(w);
			ve_w[v].push_back(w);
			visit[i]=cst[i++]=0;
			while(gets(ch))
			{
				if(strcmp(ch,"")==0)
					break;
				sscanf(ch,"%ld%ld%ld",&u,&v,&w);
				if(u>end)
					end=u;
				if(v>end)
					end=v;
				if(u<st)
					st=u;
				if(v<st)
					st=v;
				ve[u].push_back(v);
				ve[v].push_back(u);
				ve_w[u].push_back(w);
				ve_w[v].push_back(w);
				visit[i]=cst[i++]=0;
			}
			visit[i]=cst[i]=0;

		}
		else
		{
			puts("0");
			continue;
		}
		mx=0;
		dfs(st);
		j=ii;
		for(i=st;i<=end;i++)
			visit[i]=cst[i]=0;
		mx=0;
		dfs(ii);
		printf("%ld\n",cst[ii]);
		cst[ii]=0;
		for(i=st;i<=end;i++)
		{
			ve_w[i].clear();
			ve[i].clear();
		}
		i=end=1;
		st=inf;
	}
	return 0;
}


/*

5 1 6
1 4 5
6 3 9
2 6 8
6 1 7

  1 2 3
  1 5 2
  2 3 4
  2 4 5
  */