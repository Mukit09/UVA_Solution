		/****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |	     -----  /-------------\   #
#   |   \   /   |  |           |   |    /      |           |          #
#   |    \ /    |  |           |   |  /        |           |          #
#   |           |  |           |   |/          |           |          #
#   |           |  |           |   |\          |           |          #
#   |           |  |           |   |  \        |           |          #
#   |           |   \         /    |    \      |           |          #
#  ---         ---   \______ /     |         -----       -----        #
#                                                                     #
#                                                                     #
#                                                                     #
#    			codeforces = Mukit09                                  #
#    			topcoder = mukitmkbs25                                #
#    			codechef = mukit_mkbs                                 #
#    			uva = mkbs_cse09                                      #
#    			spoj = mkbs_cse09                                     #
#    			CSE, CUET                                             #
#    facebook : https://www.facebook.com/hesitated.mkbs?ref=tn_tnmn   #
#                                                                     #
#                                                                     #
\*********************************************************************/

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
#define si 11
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
i64 n,cs=1,a[85],b[85],c[85],s[85],NN,dp[1<<si][82];

i64 rec(i64 msk,i64 idx)
{
    if(idx==n)
    return (msk==NN)?0:-inf;
    if(msk==NN)
    return 0;
    i64 &ret=dp[msk][idx];
    if(ret!=-1)
    return ret;

    ret=-inf;
    if(!(msk&(1<<a[idx]))&&!(msk&(1<<b[idx]))&&!(msk&(1<<c[idx])))
    ret=s[idx]+rec(msk|(1<<a[idx])|(1<<b[idx])|(1<<c[idx]),idx+1);
    ret=max(ret,rec(msk,idx+1));
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int i;
   	while(~scanf("%lld",&n)&&n)
   	{
        mem(dp,-1);
		rep(i,0,n)
        {
            scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&s[i]);
            a[i]--,b[i]--,c[i]--;
        }
        NN=(1<<9)-1;
        if(rec(0,0)>0)
        printf("Case %lld: %lld\n",cs++,rec(0,0));
        else
        printf("Case %lld: -1\n",cs++);
    }
   	return 0;
}
