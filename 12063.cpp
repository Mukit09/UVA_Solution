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
i64 i,j,l,n,k,cs=1,dp[65][33][33][101],vis[65][33][33][101];

i64 rec(int tot,int o,int z,int md)
{
    if(tot==n)
    {
        if(!md&&o==z)
        return 1;
        return 0;
    }
    i64 &ret=dp[tot][o][z][md];
    if(vis[tot][o][z][md]>=cs)
    return ret;
    vis[tot][o][z][md]=cs;
    ret=0;
    ret+=rec(tot+1,o+1,z,(md*2+1)%k);
    ret+=rec(tot+1,o,z+1,(md*2+0)%k);
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    i64 t;
    mem(vis,0);
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld%lld",&n,&k);
   	    if(n%2||!k)
   	    {
   	        printf("Case %lld: 0\n",cs++);
            continue;
   	    }
        printf("Case %lld: %lld\n",cs++,rec(1,1,0,1%k));
    }
   	return 0;
}
