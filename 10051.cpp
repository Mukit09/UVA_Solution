        /****** BISMILLAHIR RAHMANIR RAHIM ********\

/*********************************************************************\
#   |--\     /--|  |           |   |         -----  /-------------\   #
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
#               codeforces = Mukit09                                  #
#               topcoder = Mukit09                                    #
#               codechef = mukit_mkbs                                 #
#               uva = mkbs_cse09                                      #
#               spoj = mkbs_cse09                                     #
#               CSE, CUET                                             #
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
#define si 510
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
int i,j,l,n,cs=1,cnt,sm,fg,dp[si][110],a[si][8],sv[si][110];
char ch[7][10];

int rec(int ind,int v)
{
    if(ind<1)
    return 0;
    int &ret=dp[ind][v];
    if(ret!=-1)
    return ret;
    ret=0;
    int i,tmp;
    for(i=1;i<=6;i++)
    {
        if(v==a[ind][i])
        {
            if(i%2)
            tmp=1+rec(ind-1,a[ind][i+1]);
            else
            tmp=1+rec(ind-1,a[ind][i-1]);

            if(tmp>ret)
            {
                ret=tmp;
                sv[ind][v]=i;
            }
        }
    }
    tmp=rec(ind-1,v);
    if(tmp>ret)
    {
        ret=tmp;
        sv[ind][v]=-1;
    }
    return ret;
}

void prnt(int ind,int v,int mx)
{
    if(!mx)
    return;

    if(sv[ind][v]<1)
    prnt(ind-1,v,mx);

    else if(sv[ind][v]%2)
    {
        prnt(ind-1,a[ind][sv[ind][v]+1],mx-1);
        printf("%d %s\n",ind,ch[sv[ind][v]+1]);
    }
    else
    {
        prnt(ind-1,a[ind][sv[ind][v]-1],mx-1);
        printf("%d %s\n",ind,ch[sv[ind][v]-1]);
    }
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    strcpy(ch[1],"front");
    strcpy(ch[2],"back");
    strcpy(ch[3],"left");
    strcpy(ch[4],"right");
    strcpy(ch[5],"top");
    strcpy(ch[6],"bottom");
    fg=1;

   	while(scanf("%d",&n)==1&&n)
   	{
   	    if(!fg)
   	    puts("");
   	    fg=0;

		fr(i,1,n)
		{
		    fr(j,1,6)
		    scanf("%d",&a[i][j]);
		}
		mem(dp,-1);
		int mx=0,ind,v,tmp;
		rev(i,n,1)
		{
            fr(j,1,6)
            {
                tmp=1+rec(i-1,a[i][j]);
                if(tmp>mx)
                {
                    mx=tmp;
                    ind=i;
                    v=a[i][j];
                    sv[ind][v]=j;
                }
            }
		}
		printf("Case #%d\n",cs++);
		printf("%d\n",mx);

		prnt(ind-1,v,mx-1);
		printf("%d %s\n",ind,ch[sv[ind][v]]);
    }
   	return 0;
}
