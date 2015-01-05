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
int i,j,k,l,n,m,r,fg,mat[si][si][si][si],x,y,x2,y2,cst[si][si],t;
vector<int>ve[si][si];
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

int check(int px,int py,int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&cst[x][y]>(cst[px][py]+1)&&mat[px][py][x][y]==0)
        return 1;
    return 0;
}

void bfs()
{
    int i,u,v,nwu,nwv,chk,p;
    q.push(0);
    q.push(0);
    sort(ve[0][0].begin(),ve[0][0].end());
    l=ve[0][0].size();
    p=0;
    rep(i,0,l)
    {
        t=ve[0][0][i];
        if(t!=p)
            break;
        p++;
    }
    cst[0][0]=p;
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
                nwu=u+dx[i];
                nwv=v+dy[i];
                chk=check(u,v,nwu,nwv);
                if(!chk)
                    continue;
                l=ve[nwu][nwv].size();
                sort(ve[nwu][nwv].begin(),ve[nwu][nwv].end());
                p=cst[u][v]+1;
                rep(j,0,l)
                {
                    t=ve[nwu][nwv][j];
                    if(t<p)
                    continue;
                    if(p!=t)
                        break;
                    p++;
                }
                cst[nwu][nwv]=min(cst[nwu][nwv],p);
                q.push(nwu);
                q.push(nwv);
            }
        }
    }
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d%d",&n,&m))
   	{
   	    rep(i,0,n)
   	    {
   	        rep(j,0,m)
   	        {
   	            ve[i][j].clear();
   	            cst[i][j]=inf;
   	            rep(k,0,n)
   	            {
   	                rep(l,0,m)
                        mat[i][j][k][l]=0;
   	            }
   	        }
   	    }
   	    scanf("%d",&r);
   	    while(r--)
   	    {
   	        scanf("%d%d%d%d",&x,&y,&x2,&y2);
   	        mat[x][y][x2][y2]=1;
   	    }
   	    scanf("%d",&r);
   	    while(r--)
   	    {
   	        scanf("%d%d%d",&t,&x,&y);
   	        ve[x][y].push_back(t);
   	    }
   	    fg=0;
		bfs();
		printf("%d\n",cst[n-1][m-1]);
    }
   	return 0;
}
