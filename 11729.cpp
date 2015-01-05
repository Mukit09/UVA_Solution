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
#define si 1010
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
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,fg;

int gcd(int a,int b)
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

struct ss
{
	int b,j;
}stru[si];

bool cmp(ss aa,ss bb)
{
	if(aa.j==bb.j)
		return aa.b>bb.b;
	return aa.j>bb.j;
}

int main()
{
	long  sm,cnt,mx;
   	while(~scanf("%d",&n)&&n)
   	{
		sm=cnt=0;
		fg=1;
		rep(i,0,n)
			scanf("%d%d",&stru[i].b,&stru[i].j);
		mx=-1;
		sort(stru,stru+n,cmp);
		mx=stru[0].b+stru[0].j;
		sm=stru[0].b;
		rep(i,1,n)
		{
			sm=sm+stru[i].b;
			cnt=sm+stru[i].j;
			mx=max(mx,cnt);
		}
		printf("Case %d: %lld\n",x++,mx);
    }
   	return 0;
}