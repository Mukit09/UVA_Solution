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
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,cnt,sm,fg,a[si],pr[si],p=0,save[si],ara[si],aa[45][1000];

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

void sieve()
{
	i64 num=si-5,i,j,root;
	root=sqrt(num);
	ara[1]=1;
	pr[p++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
		    pr[p++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    sieve();
    i64 t,a,b;
    scanf("%lld",&t);
   	while(t--)
   	{
   	    scanf("%lld%lld%lld",&n,&a,&b);

        i64 mx=-1,k;
   	    fr(i,0,40)
   	    {
   	        fr(j,0,1000)
   	        aa[i][j]=0;
   	    }

   	    i64 sq_a=sqrt(a);
   	    j=1;

   	    for(i=0;i<p&&pr[i]<=sq_a;i++)
   	    {
   	        if(a%pr[i]==0)
   	        {
   	            cnt=0;
   	            while(a%pr[i]==0)
   	            {
   	                a/=pr[i];
   	                cnt++;
   	            }
   	            save[j++]=pr[i];
   	            aa[0][pr[i]]=cnt;
   	            mx=pr[i];
   	        }
   	    }
   	    if(a>1)
        {
            mx=a;
            aa[0][a]=1;
            save[j++]=a;
        }

        i64 sq_b=sqrt(b);

   	    for(i=0;i<p&&pr[i]<=sq_b;i++)
   	    {
   	        if(b%pr[i]==0)
   	        {
   	            cnt=0;
   	            while(b%pr[i]==0)
   	            {
   	                b/=pr[i];
   	                cnt++;
   	            }
   	            save[j++]=pr[i];
   	            aa[1][pr[i]]=cnt;
   	            mx=max(mx,pr[i]);
   	        }
   	    }
   	    if(b>1)
        {
            aa[1][b]=1;
            mx=max(mx,b);
            save[j++]=b;
        }

		fr(i,2,n)
		{
		    fr(k,1,j-1)
		    {
		        if(aa[i-1][save[k]]||aa[i-2][save[k]])
		        aa[i][save[k]]=aa[i-1][save[k]]+aa[i-2][save[k]];
		    }
		}

		rep(i,0,p)
		{
		    if(pr[i]>mx)
		    break;
		    if(aa[n][pr[i]])
		    printf("%lld %lld\n",pr[i],aa[n][pr[i]]);
		}
		puts("");
    }
   	return 0;
}
