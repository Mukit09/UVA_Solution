// niche arekta code ache

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
#define si 1005
#define pi acos(-1.0)
#define inf 999999
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

int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int i,j,l,n,m,y,cs=1,x,cnt,sm,fg,fir[si][si],vis[si][si],cst[si][si],mn;
char ch[si][si];
queue<int>q;

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

void bfs_fire()
{
   int i,nwx,nwy,u,v;
   while(!q.empty())
   {
      u=q.front();
      q.pop();
      v=q.front();
      q.pop();
      vis[u][v]=1;
      rep(i,0,4)
      {
         nwx=u+dirx[i];
         nwy=v+diry[i];
         if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&vis[nwx][nwy]==0&&ch[nwx][nwy]!='#')
         {
            vis[nwx][nwy]=1;
            fir[nwx][nwy]=fir[u][v]+1;
            q.push(nwx);
            q.push(nwy);
         }
         else if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&vis[nwx][nwy]==1&&ch[nwx][nwy]!='#'&&fir[nwx][nwy]>fir[u][v]+1)
         {
            fir[nwx][nwy]=fir[u][v]+1;
            q.push(nwx);
            q.push(nwy);
         }
      }
   }
}

void bfs(int u,int v)
{
   int i,nwx,nwy;
   q.push(u);
   q.push(v);
   vis[u][v]=1;
   while(!q.empty())
   {
      u=q.front();
      q.pop();
      v=q.front();
      q.pop();
	  if(ch[u][v]=='J'&&(u==n-1||v==m-1||u==0||v==0))
	  {
		  mn=0;
		  break;
	  }
      rep(i,0,4)
      {
         nwx=u+dirx[i];
         nwy=v+diry[i];
         if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&ch[nwx][nwy]!='#'&&cst[u][v]+1<fir[nwx][nwy])
         {
            ch[nwx][nwy]='#';
            cst[nwx][nwy]=cst[u][v]+1;
            q.push(nwx);
            q.push(nwy);
            if(nwx==n-1||nwy==m-1||nwx==0||nwy==0)
               mn=min(mn,cst[nwx][nwy]);
         }
      }
   }
   while(!q.empty())
	   q.pop();
}

int main()
{
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		rep(i,0,n)
		{
			scanf("%s",ch[i]);
			rep(j,0,m)
			{
				fir[i][j]=inf;
				vis[i][j]=0;
				cst[i][j]=inf;
				if(ch[i][j]=='J')
					x=i,y=j;
				else if(ch[i][j]=='F')
				{
					q.push(i);
					q.push(j);
					fir[i][j]=0;
					vis[i][j]=1;
				}
			}
		}
		bfs_fire();

		cst[x][y]=0;
		mn=inf;
		bfs(x,y);
		fg=0;
		if(mn<inf)
			printf("%d\n",mn+1);
		else
			printf("IMPOSSIBLE\n");
	}
    return 0;
}
/*
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
#define si 1005
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

int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int i,j,l,n,m,y,cs=1,x,cnt,sm,fg,fir[si][si],vis[si][si],cst[si][si];
char ch[si][si];
queue<int>q;

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

void bfs_fire()
{
	int i,nwx,nwy,u,v;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		vis[u][v]=1;
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&vis[nwx][nwy]==0&&ch[nwx][nwy]!='#')
			{
				vis[nwx][nwy]=1;
				fir[nwx][nwy]=fir[u][v]+1;
				q.push(nwx);
				q.push(nwy);
			}
			else if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&vis[nwx][nwy]==1&&ch[nwx][nwy]!='#'&&fir[nwx][nwy]>fir[u][v]+1)
			{
				fir[nwx][nwy]=fir[u][v]+1;
				q.push(nwx);
				q.push(nwy);
			}
		}
	}
}

void bfs(int u,int v)
{
	int i,nwx,nwy;
	q.push(u);
	q.push(v);
	vis[u][v]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		rep(i,0,4)
		{
			nwx=u+dirx[i];
			nwy=v+diry[i];
			if(nwx<n&&nwx>=0&&nwy<m&&nwy>=0&&vis[nwx][nwy]==0&&ch[nwx][nwy]!='#'&&cst[u][v]+1<fir[nwx][nwy])
			{
				vis[nwx][nwy]=1;
				cst[nwx][nwy]=cst[u][v]+1;
				q.push(nwx);
				q.push(nwy);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d",&n,&m);
		rep(i,0,n)
		{
			scanf("%s",ch[i]);
			rep(j,0,m)
			{
				fir[i][j]=inf;
				vis[i][j]=0;
				cst[i][j]=inf;
				if(ch[i][j]=='J')
					x=i,y=j;
				else if(ch[i][j]=='F')
				{
					q.push(i);
					q.push(j);
					fir[i][j]=0;
					vis[i][j]=1;
				}
			}
		}
		bfs_fire();

		rep(i,0,n)
		{
			rep(j,0,m)
				vis[i][j]=0;
		}
		cst[x][y]=0;
		bfs(x,y);
		int mn=inf;
		fg=0;
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if((i==n-1||j==m-1||i==0||j==0)&&cst[i][j]!=inf)
				{
					fg=1;
					mn=min(mn,cst[i][j]);
				}
			}
		}
		if(fg)
			printf("%d\n",mn+1);
		else
			printf("IMPOSSIBLE\n");
    }
   	return 0;
}
*/