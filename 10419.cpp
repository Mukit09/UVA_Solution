		/****** BISMILLAHIR RAHMAnIR RAHIM ********\

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
#include <sstream>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 310
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
int i,j,l,n,cs=1,m,pth[15];
bool dp[125][1010][15];

int ara[si],cnt_p=0,pr[150];

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	pr[cnt_p++]=2;
	ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
		    pr[cnt_p++]=i;
		    pr[cnt_p++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
		ara[i+1]=1;
    }
}

bool cmp(int a, int b)
{
    stringstream ss1;
    stringstream ss2;
    ss1 << a;
    ss2 << b;
    return ss1.str() < ss2.str();
}
/*
int rec(int ind,int tot,int tk)
{
    if(ind==cnt_p)
    return 0;
    if(tk==m)
    return (tot==n)?1:0;
    int &ret=dp[ind][tot][tk];
    if(!dp[ind][tot][tk])
    return ret;
    ret=0;
    pth[tk]=pr[ind];
    if(pr[ind]+tot<=n)
    {
        ret|=rec(ind+1,pr[ind]+tot,tk+1);
        if(ret)
        return 1;
    }
    ret|=rec(ind+1,tot,tk);
    return ret;
}

*/

bool rec(int idx, int sum, int r)
{
    if (idx == cnt_p)
        return false;

    if (r == m)
    {
        if (sum == n)
            return true;
        return false;
    }

    if (sum >= n)
        return false;

    if (!dp[idx][sum][r])
        return false;

    pth[r] = pr[idx];
    if (rec(idx + 1, sum + pr[idx], r + 1))
        return true;
    if (rec(idx + 1, sum, r))
        return true;

    return dp[idx][sum][r] = false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    sieve();
 //   sort(pr,pr+cnt_p,cmp);

   	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0))
   	{
   	    mem(dp,true);
   	    if(rec(0,0,0))
   	    {
   	        printf("CASE %d:\n",cs++);
   	        printf("%d",pth[0]);
   	        rep(i,1,m)
   	        printf("+%d",pth[i]);
   	        puts("");
   	    }
   	    else
   	    printf("CASE %d:\nNo Solution.\n",cs++);
    }
   	return 0;
}
