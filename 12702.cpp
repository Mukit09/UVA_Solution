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
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,cnt,sm,fg,a[si][si],mat[15][15],res[si][si];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

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


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t,n,m;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d%d",&n,&m);
		sm=cnt=0;
		fg=1;
		fr(i,1,n)
		{
		    fr(j,1,m)
			{
			    res[i][j]=0;
			    scanf("%d",&a[i][j]);
			}
		}
		int r;
		scanf("%d%d",&r,&r);
		fr(i,1,r)
		{
		    fr(j,1,r)
		    scanf("%d",&mat[i][j]);
		}
		int origin=r/2;
		int x1,x2,y,p,q,k;
		x1=r/2;
		if(r%2==0)
		x2=x1-1;
		else
		x2=x1;
		fr(i,1,n)
		{
		    fr(j,1,m)
		    {
		        if(a[i][j])
		        {
		            for(k=i-x1,p=1;k<=i+x2;k++,p++)
		            {
		                for(l=j-x1,q=1;l<=j+x2;l++,q++)
		                {
		                    if(res[k][l])
		                    continue;
		                    res[k][l]=a[k][l]|mat[p][q];
		                }
		            }
		        }
		    }
		}
		printf("Case %d:\n",cs++);
		fr(i,1,n)
		{
		    fr(j,1,m)
		    {
		        if(j==1)
		        printf("%d",res[i][j]);
		        else
		        printf(" %d",res[i][j]);
		    }
		    puts("");
		}
    }
   	return 0;
}
