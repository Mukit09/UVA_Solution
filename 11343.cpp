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

struct ss
{
    int x1,y1,x2,y2;
}stru[si];

struct P
{
    double x,y;
    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb) {return P(bb.x-aa.x,bb.y-aa.y);}  //Make Vector
double DP(P aa,P bb){return (aa.x*bb.x+aa.y*bb.y);} // Dot Product
double CP(P aa,P bb){return aa.x*bb.y-aa.y*bb.x;} // Cross Product
double VA(P aa){return sqrt(DP(aa,aa));} // Value of Vector aa
double TRIANGLE(P aa,P bb){return CP(aa,bb)/2.0;} // Area of Triangle using CP
P ROT(P aa,double rad){return P(aa.x*cos(rad)-aa.y*sin(rad),aa.x*sin(rad)+aa.y*cos(rad));}//Rotaion with rad
P VL(P aa,double len){double v=VA(aa);return P(aa.x*len/v,aa.y*len/v);}// Make Vector of 'len' length

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%d",&n);
   	    sm=cnt=0;
		fg=1;
		fr(i,1,n)
        scanf("%d%d%d%d",&stru[i].x1,&stru[i].y1,&stru[i].x2,&stru[i].y2);

        fr(i,1,n)
        {
            fg=1;
            P a=P(stru[i].x1,stru[i].y1);
            P b=P(stru[i].x2,stru[i].y2);
            P ab=MV(a,b);
            fr(j,1,n)
            {
                if(i==j)
                continue;
                P c=P(stru[j].x1,stru[j].y1);
                P d=P(stru[j].x2,stru[j].y2);

                P ac=MV(a,c);
                P ad=MV(a,d);
                P cd=MV(c,d);
                P ca=MV(c,a);
                P cb=MV(c,b);
                double v1=CP(ab,ac);
                double v2=CP(ab,ad);
                double v3=CP(cd,ca);
                double v4=CP(cd,cb);
                if(v1*v2<0&&v3*v4<0)
                {
                    fg=0;
                    break;
                }
                if(!v1)
                {
                    int mnx=min(stru[i].x1,stru[i].x2);
                    int mxx=max(stru[i].x1,stru[i].x2);
                    int mny=min(stru[i].y1,stru[i].y2);
                    int mxy=max(stru[i].y1,stru[i].y2);
                    int cx=stru[j].x1;
                    int cy=stru[j].y1;
                    if(cx>=mnx&&cx<=mxx&&cy>=mny&&cy<=mxy)
                    {
                        fg=0;
                        break;
                    }
                }
                if(!v2)
                {
                    int mnx=min(stru[i].x1,stru[i].x2);
                    int mxx=max(stru[i].x1,stru[i].x2);
                    int mny=min(stru[i].y1,stru[i].y2);
                    int mxy=max(stru[i].y1,stru[i].y2);
                    int dx=stru[j].x2;
                    int dy=stru[j].y2;
                    if(dx>=mnx&&dx<=mxx&&dy>=mny&&dy<=mxy)
                    {
                        fg=0;
                        break;
                    }
                }
                if(!v3)
                {
                    int mnx=min(stru[j].x1,stru[j].x2);
                    int mxx=max(stru[j].x1,stru[j].x2);
                    int mny=min(stru[j].y1,stru[j].y2);
                    int mxy=max(stru[j].y1,stru[j].y2);
                    int ax=stru[i].x1;
                    int ay=stru[i].y1;
                    if(ax>=mnx&&ax<=mxx&&ay>=mny&&ay<=mxy)
                    {
                        fg=0;
                        break;
                    }
                }
                if(!v4)
                {
                    int mnx=min(stru[j].x1,stru[j].x2);
                    int mxx=max(stru[j].x1,stru[j].x2);
                    int mny=min(stru[j].y1,stru[j].y2);
                    int mxy=max(stru[j].y1,stru[j].y2);
                    int bx=stru[i].x2;
                    int by=stru[i].y2;
                    if(bx>=mnx&&bx<=mxx&&by>=mny&&by<=mxy)
                    {
                        fg=0;
                        break;
                    }
                }
            }
            if(fg)
            cnt++;
        }
        printf("%d\n",cnt);
    }
   	return 0;
}
