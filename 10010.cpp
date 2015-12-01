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
#               uva = Mukit09                                         #
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
#define si 55
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

int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,-1,1,1,-1};
int i,j,l,n,cs=1,cnt,sm,fg,m;
char ch[si][si],st[si*si];

int valid(int x,int y,int ind)
{
    int i,tmpx,tmpy,tmpInd;
    rep(i,0,8)
    {
        tmpx=x,tmpy=y,tmpInd=ind;
        while(1)
        {
            if(tmpx>=m||tmpy>=n||tmpx<0||tmpy<0)
            break;

            if(ch[tmpx][tmpy]!=st[tmpInd])
            break;

            tmpInd++;
            if(tmpInd==l)
            return 1;

            tmpx+=dx[i];
            tmpy+=dy[i];
        }
    }
    return 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int t,k,chk,ii;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d",&m,&n);
		rep(i,0,m)
        {
            scanf("%s",ch[i]);
            rep(j,0,n)
            {
                if(ch[i][j]>=65&&ch[i][j]<=90)
                ch[i][j]+=32;
            }
        }

        scanf("%d",&k);
        while(k--)
        {
            scanf("%s",st);
            l=strlen(st);
            rep(i,0,l)
            {
                if(st[i]>=65&&st[i]<=90)
                st[i]+=32;
            }

            rep(i,0,m)
            {
                rep(j,0,n)
                {
                    if(ch[i][j]==st[0])
                    {
                        chk=valid(i,j,0);
                        if(chk)
                        {
                            printf("%d %d", i+1, j+1);
                            goto prnt;
                        }
                    }
                }
            }
            prnt:
            puts("");
        }
        if(t)
        puts("");
    }
   	return 0;
}

