
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
#define si 110
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
int i,j,l,n,cs=1,cnt,sm,fg,a[si];
char ch[si],prev[si];

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int t,k,w,tmp, tmp_j;
    scanf("%d",&t);

   	while(t--)
   	{
   	    scanf("%d%d",&k,&w);
		scanf("%s",prev);
		sm=k;
		w--;
		while(w--)
		{
		    fg=0;
		    scanf("%s",ch);
		    if(strcmp(ch,prev)==0)
		    continue;
		    i=0;
		    rep(j,0,k)
		    {
		        if(ch[i]==prev[j])
		        {
		            tmp=i;
		            tmp_j=j;
		            while(tmp<k&&tmp_j<k&&ch[tmp]==prev[tmp_j])
		            {
		                tmp_j++;
		                tmp++;
		            }
		            if(tmp_j==k)
		            {
		                fg=1;
		                sm+=j; // j theke started
		                break;
		            }
		            else
		            i=0;
		        }
		    }
		    if(!fg)
		    sm+=k;
		    strcpy(prev, ch);
		}
		printf("%d\n", sm);
    }
   	return 0;
}
