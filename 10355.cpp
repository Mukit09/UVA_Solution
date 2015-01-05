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
#define si 100010
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
int i,j,l,n,cs=1,cnt,sm,fg;
char ch[15];

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
    double x,y,z,r;
    P(double x=0,double y=0,double z=0,double r=0)
    {
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
    }
    void scan(){scanf("%lf%lf%lf",&x,&y,&z);}
}A,B,C;

P MV(P aa,P bb){return P(bb.x-aa.x,bb.y-aa.y,bb.z-aa.z);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y+aa.z*bb.z);} // Dot Product
P CP(P aa,P bb){return P(aa.y*bb.z-aa.z*bb.y,aa.z*bb.x-aa.x*bb.z,aa.x*bb.y-aa.y*bb.x);} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));} // Value of Vector aa
P ADD(P aa,P bb){return P(aa.x+bb.x,aa.y+bb.y,aa.z+bb.z);}
//P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}//Rotaion with rad
P VL(P aa,double len){double v=VA(aa);return P(aa.x*len/v,aa.y*len/v,aa.z*len/v);}// Make Vector of 'len' length
double distance_3d(P aa,P bb){return sqr(aa.x-bb.x)+sqr(aa.y-bb.y)+sqr(aa.z-bb.z);}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    double d1,d2,d,h;
   	while(~scanf("%s",&ch))
   	{
   	    double ans=0.0;
		fg=1;
		A.scan();
		B.scan();
		P AB=MV(A,B);
		P BA=MV(B,A);
		double tot=sqrt(distance_3d(A,B));
		if(compare(tot,0.00))
		fg=0;
		scanf("%d",&n);
		rep(i,0,n)
		{
		    scanf("%lf%lf%lf%lf",&C.x,&C.y,&C.z,&C.r);
		    P BC=MV(B,C);
            P AC=MV(A,C);
		    d=DP(AC,AB)/VA(AB);
            h=fabs(VA(CP(AB,AC))/VA(AB));
            if(!fg||DP(AB,AC)*DP(BA,BC)<0)
            continue;
            if(h<C.r)
            {
                d1=sqrt(distance_3d(A,C));
                d2=sqrt(distance_3d(B,C));
                if(d1>C.r&&d2>C.r)
                ans+=(2.0*sqrt(sqr(C.r)-sqr(h)));
                else if(d1>C.r)
                ans+=(sqrt(sqr(C.r)-sqr(h))+sqrt(distance_3d(C,B)-sqr(h)));
                else if(d2>C.r)
                ans+=(sqrt(sqr(C.r)-sqr(h))+sqrt(distance_3d(A,C)-sqr(h)));
                else
                ans+=sqrt(distance_3d(A,B));
            }
		}
		puts(ch);
		if(!fg)
		printf("0.00\n");
		else
		printf("%.2lf\n",((ans*100.00)/tot)+1e-7);
    }
   	return 0;
}
