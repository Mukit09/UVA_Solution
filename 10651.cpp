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
#define si 15
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
int cs=1,dp[(1<<12)+10];
char ch[si];

int rec(int msk)
{
    if(!msk)
    return 0;
    int &ret=dp[msk];
    if(ret!=-1)
    return ret;
    int i=0,j,sm=0,fg=0,v,k;
    ret=inf;
    rev(k,11,0)
    {
        if(msk&(1<<i))
        {
            j=i-1;
            if(msk&(1<<j)&&j>=0)
            {
                if(j&&!(msk&(1<<(j-1))))
                {
                    v=msk;
                    v=v|(1<<(j-1));
                    v=v&~(1<<i);
                    v=v&~(1<<j);
                    ret=min(ret,rec(v));
                    fg=1;
                }
                if(i+1<12&&!(msk&(1<<(i+1))))
                {
                    v=msk;
                    v=v|(1<<(i+1));
                    v=v&~(1<<j);
                    v=v&~(1<<i);
                    ret=min(ret,rec(v));
                    fg=1;
                }
            }
        }
        i++;
    }
    if(!fg)
    {
        i=11;
        rep(i,0,12)
        {
            if(msk&(1<<i))
            sm++;
        }
        ret=sm;
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t,v,i,j;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%s",ch);
        mem(dp,-1);
        v=0;
        j=0;
        rev(i,11,0)
        {
            if(ch[i]=='o')
            v|=(1<<j);
            j++;
        }
        printf("%d\n",rec(v));
    }
   	return 0;
}
