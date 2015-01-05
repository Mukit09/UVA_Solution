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
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,dp[si][si];
char ch[si];

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

int rec(int i,int j)
{
	if(i>=j)
		return 0;
	int &ret=dp[i][j];
	if(ret!=-1)
		return ret;
	if(ch[i]==ch[j])
		ret=rec(i+1,j-1);
	else
	{
		ret=rec(i,j-1)+1;
		ret=min(ret,rec(i+1,j)+1);
		ret=min(ret,rec(i+1,j-1)+1);
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%s",ch);
		l=strlen(ch);
		rep(i,0,l)
		{
			rep(j,0,l)
				dp[i][j]=-1;
		}
		printf("Case %d: %d\n",x++,rec(0,l-1));
    }
   	return 0;
}