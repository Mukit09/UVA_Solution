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
#define si 70
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
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two poi64s
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

i64 dx[]={0,0,1,-1};
i64 dy[]={1,-1,0,0};
i64 i,j,l,n,x=1,cnt,sm,fg,dp[si][5][si],s;


i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

i64 gcd(i64 a,i64 b)
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


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

i64 rec(i64 ind,i64 fg,i64 taken)
{
    if(ind>n)
    return taken==s?1:0;
    i64 &ret=dp[ind][fg][taken];
    if(ret!=-1)
    return ret;
    ret=rec(ind+1,2,taken);
    if(fg==1)
    ret=ret+rec(ind+1,1,taken+1);
    else
    ret=ret+rec(ind+1,1,taken);
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%lld%lld",&n,&s))
   	{
   	    if(n<0&&s<0)
   	    break;
   	    mem(dp,-1);
   	    printf("%lld\n",rec(2,1,1)+rec(2,2,0));
    }
   	return 0;
}
