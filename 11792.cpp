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
#define si 10010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,x=1,cnt,sm,fg,res[si],cst[si],a[si],s,u,v;
queue<int>q;
vector<int>ve[si];

/*
i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}*/

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

/*
i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}
*/

int bfs(int u)
{
	int i,ret=0;
	for(i=1;i<=n;i++)
		cst[i]=-1;
	cst[u]=0;
	q.push(u);

	while(!q.empty())
	{
		u=q.front();
		q.pop();
		l=ve[u].size();
		for(i=0;i<l;i++)
		{
			v=ve[u][i];
			if(cst[v]<0)
			{
				cst[v]=cst[u]+1;
				q.push(v);
				if(res[v]>1)
					ret+=cst[v];
			}
		}
	}
	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d",&n,&s);
		j=0;
		fr(i,1,n)
		{
			ve[i].clear();
			res[i]=cst[i]=0;
		}
		for(i=1;i<=s;i++)
		{
			scanf("%d",&v);
			res[v]++;
			while(~scanf("%d",&u)&&u)
			{
				ve[v].push_back(u);
				ve[u].push_back(v);
				res[u]++;
				if(res[u]>1&&cst[u]==0)
				{
					cst[u]=1;
					a[j++]=u;
				}
				v=u;
			}
		}
		sort(a,a+j);
		int ans,mn=inf;
		for(i=0;i<j;i++)
		{
			sm=bfs(a[i]);
			if(mn>sm)
			{
				mn=sm;
				ans=a[i];
			}
		}
		printf("Krochanska is in: %d\n",ans);
    }
   	return 0;
}
