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
#define si 50010
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

//typedef __int64 i64;
typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,cnt,sm,fg,a[1000010],mn,mx,nw,ans1,ans2,ans3,ans4,r;

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

int ara[si],cnt_p=1,pr[si];

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	pr[cnt_p++]=2;
	ara[0]=ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
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

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    sieve();

   	while(~scanf("%lld%lld",&l,&r))
   	{
   	    for(i=0;i<=r-l;i++)
   	    a[i]=0;
   	    if(l==1)
   	    l++;

   	    for(i=1;i<cnt_p;i++)
   	    {
   	        if(r/pr[i]==0)
   	        break;
   	        j=l/pr[i];
   	        if(l%pr[i]!=0)
   	        j++;

   	        j*=pr[i];
   	        if(pr[i]==j)
   	        j+=pr[i];
   	        j-=l;
            for(j=j;j<=r-l;j+=pr[i])
   	        a[j]=1;
   	    }
   	    fg=1;
   	    mn=inf,mx=-inf;
   	    for(i=0;i<=r-l;i++)
   	    {
   	        if(a[i]==0&&fg)
   	        {
   	            fg=0;
   	            nw=i;
   	        }
   	        else if(a[i]==0)
   	        {
   	            if(i-nw<mn)
   	            {
   	                mn=i-nw;
   	                ans1=nw,ans2=i;
   	            }
   	            if(i-nw>mx)
   	            {
   	                mx=i-nw;
   	                ans3=nw,ans4=i;
   	            }
   	            nw=i;
   	        }
   	    }
   	    if(mn==inf)
   	    puts("There are no adjacent primes.");
   	    else
   	    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",ans1+l,ans2+l,ans3+l,ans4+l);
    }
   	return 0;
}
