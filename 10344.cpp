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

int i,j,l,n,x=1,cnt,sm,fg,a[8];
char ch[8];

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

int rec(int ind,int total)
{
	if(ind>4)
	{
		if(total==23)
			return 1;
		return 0;
	}
	int p1,p2,p3;
	p1=rec(ind+1,total+a[ind]);
	p2=rec(ind+1,total-a[ind]);
	p3=rec(ind+1,total*a[ind]);
	return p1|p2|p3;
}

int main()
{
	int chk;
   	while(~scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4])&&(a[0]||a[1]||a[2]||a[3]||a[4]))
   	{
		sort(a,a+5);
		do
		{
			chk=rec(1,a[0]);
			if(chk)
				break;
		}while(next_permutation(a,a+5));
		if(chk)
			puts("Possible");
		else
			puts("Impossible");
    }
   	return 0;
}