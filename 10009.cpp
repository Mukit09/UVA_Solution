#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

vector<long>ve[1010];
queue<long>q;
map<string,long>mp;
long u,v,n,e,t,visit[1010],Q,p[1010],k;
char ch1[1050],ch2[1050],st[1010][1050];

void bfs(long node)
{
	long i,u,v;
	visit[node]=1;
	q.push(node);
	while(!q.empty())
	{
		u=q.front();
		for(i=0;i<ve[u].size();i++)
		{
			v=ve[u][i];
			if(visit[v]==0)
			{
				q.push(v);
				visit[v]=1;
				p[v]=u;
			}
		}
		q.pop();
	}
}

int main()
{
	long i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&e,&Q);
		n=1;
		for(i=1;i<=e;i++)
		{
			scanf("%s%s",ch1,ch2);
			if(mp[ch1]==0)
			{
				mp[ch1]=n;
				strcpy(st[n],ch1);
				n++;
			}
			if(mp[ch2]==0)
			{
				mp[ch2]=n;
				strcpy(st[n],ch2);
				n++;
			}
			ve[mp[ch1]].push_back(mp[ch2]);
			ve[mp[ch2]].push_back(mp[ch1]);
		}
		for(i=1;i<=Q;i++)
		{
			scanf("%s%s",ch1,ch2);
			u=mp[ch1];
			v=mp[ch2];
			for(j=1;j<n;j++)
			{
				p[j]=j;
				visit[j]=0;
			}
			bfs(u);
			k=0;
			while(v!=p[v])
			{
				ch1[k++]=st[v][0];
				v=p[v];
			}
			ch1[k]=st[u][0];
			for(j=k;j>=0;j--)
				printf("%c",ch1[j]);
			printf("\n");
		}
		mp.clear();
		for(i=1;i<n;i++)
			ve[i].clear();
		if(t)
			printf("\n");
	}
	return 0;
}