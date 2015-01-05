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
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,x=1,cnt,sm,fg,a[si][si],k,r,c,m,y,d,vis[si][si],cst[si][si];
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

void bfs()
{
	int u,v,nwx,nwy;
	if(!a[1][1])
		q.push(1),q.push(1);
	a[1][1]=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		v=q.front();
		q.pop();
		if(!fg)
		{
			rep(i,0,4)
			{
				nwx=u+dx[i];
				nwy=v+dy[i];
				if(nwx>0&&nwx<=r&&nwy>0&&nwy<=c&&a[nwx][nwy]==0)
				{
					a[nwx][nwy]=1;
					cst[nwx][nwy]=cst[u][v]+1;
					if(nwx==r&&nwy==c)
					{
						fg=1;
						break;
					}
					q.push(nwx);
					q.push(nwy);
				}
			}
		}
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d%d",&r,&c)&&(r||c))
   	{
		fg=0;
		fr(i,1,r)
		{
			fr(j,1,c)
				a[i][j]=vis[i][j]=cst[i][j]=0;
		}
		scanf("%d",&m);
		fr(i,1,m)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		scanf("%d",&n);
		fr(i,1,n)
		{
			scanf("%d%d%d",&x,&y,&l);
			l*=l;
			fr(j,1,r)
			{
				fr(k,1,c)
				{
					d=dist(x,y,j,k);
					if(d<=l)
						a[j][k]=1;
				}
			}
		}
		bfs();
		if(fg)
			printf("%d\n",cst[r][c]);
		else
			puts("Impossible.");
    }
   	return 0;
}