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
int i,j,l,n,cs=1,cnt,sm,fg,a[si],tree[si*3],u,v;
char ch[5],res[si];

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

void build(int node,int lft,int rht)
{
    if(lft==rht)
    {
        if(a[lft]<0)
        a[lft]=-1;
        else if(a[lft]>0)
        a[lft]=1;
        tree[node]=a[lft];
        return;
    }
    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    build(lc,lft,m);
    build(rc,m+1,rht);
    tree[node]=tree[lc]*tree[rc];
}

void update(int node,int lft,int rht)
{
    if(lft>u||rht<u)
    return;
    if(lft>=u&&rht<=u)
    {
        if(v<0)
        v=-1;
        else if(v>0)
        v=1;
        tree[node]=v;
        return;
    }
    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    update(lc,lft,m);
    update(rc,m+1,rht);
    tree[node]=tree[lc]*tree[rc];
}

int query(int node,int lft,int rht)
{
    if(lft>v||rht<u)
    return 1;
    if(lft>=u&&rht<=v)
    return tree[node];
    int lc,rc,m;
    lc=node*2;
    rc=lc+1;
    m=(lft+rht)/2;
    return query(lc,lft,m)*query(rc,m+1,rht);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int q,ans;
   	while(~scanf("%d%d",&n,&q))
   	{
   	    j=0;
		fr(i,1,n)
        scanf("%d",&a[i]);
        build(1,1,n);
        while(q--)
        {
            scanf("%s%d%d",ch,&u,&v);
            if(ch[0]=='C')
            update(1,1,n);
            else
            {
                ans=query(1,1,n);
                if(!ans)
                res[j++]='0';
                else if(ans<0)
                res[j++]='-';
                else
                res[j++]='+';
            }
        }
        res[j]=0;
        puts(res);
    }
   	return 0;
}
