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
#define si 100010
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
int dw[]={1,0,0,0,-1,0,0,0};
int dx[]={0,1,0,0,0,-1,0,0};
int dy[]={0,0,1,0,0,0,-1,0};
int dz[]={0,0,0,1,0,0,0,-1};
int i,j,l,n,fg,a1[si][15],a2[si][15],a3[si][15],a4[si][15],st[5],ed[5],cst[15][15][15][15],vis[15][15][15][15],k;
queue<int>qq;

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

void bfs(int p,int q,int r,int s)
{
	int nwp,nwq,nwr,nws,fnd;
	qq.push(p);
	qq.push(q);
	qq.push(r);
	qq.push(s);
	while(!qq.empty())
	{
		p=qq.front();
		qq.pop();
		q=qq.front();
		qq.pop();
		r=qq.front();
		qq.pop();
		s=qq.front();
		qq.pop();
		if(!fg)
		{
			rep(i,0,8)
			{
				nwp=p+dw[i];
				nwq=q+dx[i];
				nwr=r+dy[i];
				nws=s+dz[i];
				if(nwp>9)
					nwp=0;
				else if(nwp<0)
					nwp=9;
				if(nwq>9)
					nwq=0;
				else if(nwq<0)
					nwq=9;
				if(nwr>9)
					nwr=0;
				else if(nwr<0)
					nwr=9;
				if(nws>9)
					nws=0;
				else if(nws<0)
					nws=9;
				if(vis[nwp][nwq][nwr][nws]==0&&!fg)
				{
					vis[nwp][nwq][nwr][nws]=1;
					fnd=1;
					rep(j,0,n)
					{
						if(a1[j][nwp]&&a2[j][nwq]&&a3[j][nwr]&&a4[j][nws])
						{
							fnd=0;
							break;
						}
					}
					if(!fnd)
						continue;
					cst[nwp][nwq][nwr][nws]=cst[p][q][r][s]+1;
					if(nwp==ed[0]&&nwq==ed[1]&&nwr==ed[2]&&nws==ed[3])
					{
						fg=1;
						break;
					}
					qq.push(nwp);
					qq.push(nwq);
					qq.push(nwr);
					qq.push(nws);
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t,p,q,r,s;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d%d%d%d",&st[0],&st[1],&st[2],&st[3]);
		scanf("%d%d%d%d",&ed[0],&ed[1],&ed[2],&ed[3]);
		fg=0;
		scanf("%d",&n);
		rep(i,0,n)
		{
			rep(j,0,10)
				a1[i][j]=a2[i][j]=a3[i][j]=a4[i][j]=0;
			scanf("%d%d%d%d",&p,&q,&r,&s);
			if(st[0]==p&&st[1]==q&&st[2]==r&&st[3]==s)
				fg=1;
			else if(ed[0]==p&&ed[1]==q&&ed[2]==r&&ed[3]==s)
				fg=1;
			a1[i][p]=a2[i][q]=a3[i][r]=a4[i][s]=1;
		}
		if(fg)
		{
			puts("-1");
			continue;
		}
		if(st[0]==ed[0]&&st[1]==ed[1]&&st[2]==ed[2]&&st[3]==ed[3])
		{
			puts("0");
			continue;
		}
		rep(i,0,10)
		{
			rep(j,0,10)
			{
				rep(k,0,10)
				{
					rep(l,0,10)
						vis[i][j][k][l]=cst[i][j][k][l]=0;
				}
			}
		}

		bfs(st[0],st[1],st[2],st[3]);
		if(fg)
			printf("%d\n",cst[ed[0]][ed[1]][ed[2]][ed[3]]);
		else
			puts("-1");
    }
   	return 0;
}