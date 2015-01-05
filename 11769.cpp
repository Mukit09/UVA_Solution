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
#    codeforces = Mukit09                                             #
#    topcoder = mukitmkbs25                                           #
#    codechef = mukit_mkbs                                            #
#    uva = mkbs_cse09                                                 #
#    spoj = mkbs_cse09                                                #
#    usaco = mukitmk1                                                 #
#    CSE, CUET                                                        #
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
#define si 30
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
int i,j,k,l,n,cs=1;
double sm;

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

/*
int ara[si],cnt_p=1,pr[si];

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
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}
*/

struct P
{
    double x,y,z;
    P(double x=0,double y=0,double z=0)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
}stru[si];

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y,bb.z-aa.z);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y+aa.z*bb.z);} // Dot Product
P CP(P aa,P bb){return P(aa.y*bb.z-bb.y*aa.z,bb.x*aa.z-aa.x*bb.z,aa.x*bb.y-bb.x*aa.y);} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d",&n)&&n)
   	{
   	    sm=0;
		rep(i,0,n)
        scanf("%lf%lf%lf",&stru[i].x,&stru[i].y,&stru[i].z);

        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                rep(k,j+1,n)
                {
                    P c=CP(MV(stru[i],stru[j]),MV(stru[i],stru[k]));
                    int pos=0,neg=0;
                    rep(l,0,n)
                    {
                        if(l!=i&&l!=j&&l!=k)
                        {
                            double chk=DP(c,MV(stru[i],stru[l]));
                            if(chk<0)
                            neg++;
                            else if(chk>0)
                            pos++;
                        }
                    }
                    if(pos==n-3||neg==n-3)
                    sm+=VA(c);
                }
            }
        }
        printf("Case %d: %.2lf\n",cs++,sm*0.5);
    }
   	return 0;
}
