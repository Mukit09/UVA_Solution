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
#define si 110
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
int i,j,l,n,cs=1,cnt,a[si][si],d[si][si],e,t,m;

struct dij
{
    int u,w;
    dij(int a,int b)
    {
        u=a,w=b;
    }

    bool operator < (const dij& p) const {return w>p.w;}
};

void dijkstra(int s,int p)
{
    priority_queue<dij>q;
    q.push(dij(s,0));
    int i,u,v;
    while(!q.empty())
    {
        dij nw=q.top();
        q.pop();
        u=nw.u;
        if(u==e)
        return;
        fr(i,1,n)
        {
            if(i==u)
            continue;
            if(a[u][i]>=0&&a[u][i]+d[p][u]<d[p][i])
            {
                d[p][i]=d[p][u]+a[u][i];
                q.push(dij(i,d[p][i]));
            }
        }
    }
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int T,u,v,w;
    scanf("%d",&T);
   	while(T--)
   	{
   	    scanf("%d%d%d%d",&n,&e,&t,&m);
   	    fr(i,1,n)
   	    {
   	        fr(j,1,n)
   	        a[i][j]=-1,d[i][j]=inf;
   	    }

   	    while(m--)
   	    {
   	        scanf("%d%d%d",&u,&v,&w);
   	        a[u][v]=w;
   	    }
   	    cnt=0;
   	    fr(i,1,n)
   	    {
   	        d[i][i]=0;
   	        dijkstra(i,i);
   	        if(d[i][e]<=t)
   	        cnt++;
   	    }
   	    printf("%d\n",cnt);
   	    if(T)
   	    puts("");
    }
   	return 0;
}
