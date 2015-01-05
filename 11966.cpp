
/*
//Using DFS//
//Next time I did it with Union Find,which is given below

#include<stdio.h>
#include<math.h>
#include<vector>
#define si 1010
using namespace std;
vector<long>ve[si];

double a;
long visit[si];

struct
{
	double x,y;
}s[si];

double area(double x1,double y1,double x2,double y2)
{
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return a;
}

void dfs(long node)
{
	long i,u,l;
	l=ve[node].size();
	visit[node]=1;
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			dfs(u);
		}
	}
}

int main()
{
	long n,i,j,t,k=1,cnt;
	double d;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%lf",&n,&d);
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			scanf("%lf%lf",&s[i].x,&s[i].y);
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				a=area(s[i].x,s[i].y,s[j].x,s[j].y);
				if((d-a)>0.001)
				{
					ve[i].push_back(j);
					ve[j].push_back(i);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				visit[i]=1;
				cnt++;
				dfs(i);
			}
		}
		printf("Case %ld: %ld\n",k++,cnt);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}
*/

#include<stdio.h>
#include<math.h>
#define si 1010

double a;
int p[si],r[si],res[si];

struct
{
	double x,y;
}s[si];

double area(double x1,double y1,double x2,double y2)
{
	a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return a;
}

void link(int x,int y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int find(int x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

int main()
{
	long n,i,j,t,k=1,cnt,pu,pv;
	double d;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%lf",&n,&d);
		d=d*d;
		for(i=1;i<=n;i++)
		{
			r[i]=1;
			p[i]=i;
			res[i]=0;
			scanf("%lf%lf",&s[i].x,&s[i].y);
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				a=area(s[i].x,s[i].y,s[j].x,s[j].y);
				if((d-a)>0.001)
				{
					pu=find(i);
					pv=find(j);
					if(pu!=pv)
						link(pu,pv);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			pu=find(i);
			res[pu]++;
		}
		for(i=1;i<=n;i++)
		{
			if(res[i])
				cnt++;
		}
		printf("Case %ld: %ld\n",k++,cnt);
	}
	return 0;
}
