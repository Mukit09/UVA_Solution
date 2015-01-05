#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 210
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define pb push_back
#define mpair make_pair
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < eps ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,cnt,sm,fg,a[si],cst[si],vis[si],chk[si];
vector<int>ve[si];

struct ss
{
    int u,v,w;
}stru[si*si];

void dfs(int node)
{
    int i,l=ve[node].size(),u;
    rep(i,0,l)
    {
        u=ve[node][i];
        if(!vis[u])
        {
            vis[u]=1;
            cst[u]=-inf;
            dfs(u);
        }
    }
}

void dfs1(int node)
{
    chk[node]=1;
    int i,l=ve[node].size(),u;
    rep(i,0,l)
    {
        u=ve[node][i];
        if(!chk[u])
        {
            chk[u]=1;
            dfs1(u);
        }
    }
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int u,v,w,m,q;
   	while(scanf("%d",&n)==1)
   	{
   	    sm=cnt=0;
		fg=1;
		fr(i,1,n)
		{
		    scanf("%d",&a[i]);
		    cst[i]=inf;
		    vis[i]=chk[i]=0;
		    ve[i].clear();
		}

		scanf("%d",&m);
		fr(i,1,m)
		{
            scanf("%d%d",&u,&v);
            ve[u].pb(v);
            stru[i].u=u;
            stru[i].v=v;
            stru[i].w=(a[v]-a[u])*(a[v]-a[u])*(a[v]-a[u]);
		}

		cst[1]=0;
		fr(i,1,n)
		{
		    fr(j,1,m)
		    {
		        u=stru[j].u;
		        v=stru[j].v;
		        w=stru[j].w;
		        if(cst[u]+w<cst[v]&&i<n)
		        cst[v]=cst[u]+w;
		        else if(cst[u]+w<cst[v])
		        cst[v]=-inf;
		    }
		}
		fr(i,1,n)
		{
		    if(cst[i]==-inf&&!vis[i])
		    dfs(i);
		}
		dfs1(1);
		printf("Set #%d\n",cs++);
		scanf("%d",&q);
		while(q--)
		{
		    scanf("%d",&u);
		    if(cst[u]<3||!chk[u]||u>n)
		    printf("?\n");
		    else
		    printf("%d\n",cst[u]);
		}
    }
   	return 0;
}
