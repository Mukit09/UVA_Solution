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
#define neg_inf -99999999
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

int i,j,l,n,x=1,cnt,sm,fg,dp[25][205],mx,c;
vector<int>val[25];

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

int rec(int garment,int taken)
{
	if(garment>c)
	{
		if(taken<=mx)
			return taken;
		return neg_inf;
	}
	int &ret=dp[garment][taken];
	if(ret!=-1)
		return ret;
	int p1=0,i,v;
	for(i=0;i<val[garment].size();i++)
	{
		v=val[garment][i];
		if(taken+v<=mx)
			p1=rec(garment+1,taken+v);	
		ret=max(p1,ret);
	}
	return ret;
}

int main()
{
	int t,i,j,re,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&mx,&c);
		for(i=1;i<=c;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&n);
				val[i].push_back(n);
			}
			for(j=0;j<=mx;j++)
				dp[i][j]=-1;
		}
		re=rec(1,0);
		if(re)
			printf("%d\n",re);
		else
			printf("no solution\n");
		for(i=1;i<=c;i++)
			val[i].clear();
	}
	return 0;
}