#include<stdio.h>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<map>
using namespace std;
#define inf 99999
#define si 210
map<string,int>mp;
vector<int>ve[si];
queue<int>q;
char ch[si][15],st[30];
int visit[si],cst[si];

void bfs(int node)
{
	int i,u,l,v;
	visit[node]=1;
	q.push(node);
	while(!q.empty())
	{
		u=q.front();
		l=ve[u].size();
		for(i=0;i<l;i++)
		{
			v=ve[u][i];
			if(visit[v]==0)
			{
				visit[v]=1;
				cst[v]=cst[u]+1;
				q.push(v);
			}
		}
		q.pop();
	}
}

int main()
{
	int t,i,k,s,d,l,ll,cnt,u,v,n,j;
	char *pch;
	scanf("%d",&t);
	while(getchar()!='\n');
	gets(st);
	while(t--)
	{
		i=1;k=1;
		while(gets(ch[i]))
		{
			if(strcmp(ch[i],"*")==0)
				break;
			ve[i].clear();
			mp[ch[i]]=k++;
			i++;
		}
		n=i;
		for(i=0;i<n;i++)
		{
			l=strlen(ch[i]);
			for(j=i+1;j<n;j++)
			{
				ll=strlen(ch[j]);
				if(l==ll)
				{
					cnt=0;
					for(k=0;k<l;k++)
					{
						if(ch[i][k]!=ch[j][k])
							cnt++;
						if(cnt>1)
							break;
					}
					if(cnt==1)
					{
						u=mp[ch[i]];
						v=mp[ch[j]];
						ve[u].push_back(v);
						ve[v].push_back(u);
					}
				}
			}
		}
		while(gets(st))
		{
			if(strcmp(st,"")==0)
				break;
			for(i=1;i<n;i++)
			{
				visit[i]=0;
				cst[i]=inf;
			}
			pch=strtok(st," ");
			printf("%s",pch);
			s=mp[pch];
			pch=strtok(NULL," ");
			printf(" %s",pch);
			d=mp[pch];
			cst[s]=0;
			bfs(s);
			printf(" %d\n",cst[d]);
		}
		if(t)
			printf("\n");
		mp.clear();
	}
	return 0;
}
