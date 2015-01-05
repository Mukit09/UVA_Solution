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
int i,j,l,n,cs=1,sm;

char st[si][85];

struct node
{
    int cnt,i;
    node *nxt[30];
    node()
    {
        cnt=0;
        for(i=0;i<26;i++)
        nxt[i]=0;
    }
}*root;

void insert(int ind)
{
    int i,j;
    node *nw=root;
    for(i=0;i<l;i++)
    {
        j=st[ind][i]-97;
        if(!nw->nxt[j])
        nw->nxt[j]=new node();
        nw=nw->nxt[j];
        nw->cnt++;
    }
}

int check(int ind)
{
    int i,j,ret=0,f;
    l=strlen(st[ind]);
    node *nw=root;
    f=nw->cnt;

    for(i=0;i<l;i++)
    {
        j=st[ind][i]-97;

        nw=nw->nxt[j];
        if(f!=nw->cnt)
        ret++;
        f=nw->cnt;
        if(nw->cnt==1)
        return ret;
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(scanf("%d",&n)==1)
   	{
   	    root=new node();
        sm=0;
		fr(i,1,n)
		{
		    scanf("%s",st[i]);
		    l=strlen(st[i]);
		    insert(i);
		}
		fr(i,1,n)
        sm+=check(i);

        printf("%.2lf\n",(double)sm/(double)n);
    }
   	return 0;
}

