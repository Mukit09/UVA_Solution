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
#define si 17
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
i64 l,n,cs=1,sm,dp[(1<<si)+10][110],s,m,fg,ans,v,a[110],NN,chk[110],vis[(1<<si)+10][110];
char ch[10010];
vector<i64>ve[110];

i64 rec(i64 msk,i64 ind)
{
    if(ind==n)
    return (msk==NN)?0:inf;
    if(msk==NN)
    return 0;
    i64 &ret=dp[msk][ind];
    if(vis[msk][ind]==cs)
    return ret;
    vis[msk][ind]=cs;
    i64 i,j,v,l,p;
    ret=inf;
    if(chk[ind])
    {
        v=msk;
        l=ve[ind].size();
        rep(j,0,l)
        {
            p=ve[ind][j];
            if(!(v&(1<<p)))
            v=v|(1<<p);
            else
            v=v|(1<<(p+s));
        }
        ret=min(ret,a[ind]+rec(v,ind+1));
    }
    ret=min(ret,rec(msk,ind+1));
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    i64 i,j;
   	while(~scanf("%lld%lld%lld",&s,&m,&n)&&s)
   	{
   	    NN=(1<<(2*s))-1;
   	    ans=v=0;
   	    while(getchar()!='\n');
   	    fr(j,1,m)
   	    {
   	        gets(ch);
   	        l=strlen(ch);
   	        sm=0;
   	        rep(i,0,l)
   	        {
   	            if(ch[i]==' ')
   	            break;
   	            if(ch[i]>=48&&ch[i]<=57)
   	            sm=sm*10+(ch[i]-48);
   	        }
   	        ans+=sm;
   	        while(ch[i]!=' ')
   	        i++;
   	        sm=0;
   	        rep(i,i,l)
   	        {
   	            if(ch[i]>=48&&ch[i]<=57)
   	            {
   	                sm=ch[i]-48;
   	                sm--;
   	                if(!(v&(1<<sm)))
   	                v=v|(1<<sm);
   	                else
   	                v=v|(1<<(sm+s));
   	            }
   	        }
   	    }
		rep(j,0,n)
		{
		    chk[j]=0;
		    gets(ch);
		    l=strlen(ch);
   	        sm=0;
   	        rep(i,0,l)
   	        {
   	            if(ch[i]==' ')
   	            break;
   	            if(ch[i]>=48&&ch[i]<=57)
   	            sm=sm*10+(ch[i]-48);
   	        }
   	        a[j]=sm;
   	        while(ch[i]!=' ')
   	        i++;
   	        sm=0;
   	        fg=0;
   	        rep(i,i,l)
   	        {
   	            if(ch[i]>=48&&ch[i]<=57)
   	            {
   	                sm=ch[i]-48;
   	                sm--;
   	                ve[j].pb(sm);
   	                if(!(v&(1<<sm)))
   	                fg=1;
   	                if(!(v&(1<<(sm+s))))
   	                fg=1;
   	            }
   	        }
   	        if(fg)
   	        chk[j]=1;
		}
		printf("%lld\n",ans+rec(v,0));
		rep(i,0,n)
		ve[i].clear();
		cs++;
    }
   	return 0;
}
