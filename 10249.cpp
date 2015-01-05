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
#define si 101
#define pi acos(-1.0)
#define inf (1<<30)-1

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

int i,j,l,n,x=1,sm,cnt,fg,mx_tm,mx_tb,m,mx;
vector<int>ve[si];

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

struct ss
{
	int n,ind;
}tm[si],tb[si];

bool cmp(ss aa, ss bb)
{
	return aa.n<bb.n;
}

int main()
{
    while(~scanf("%d%d",&m,&n)&&(m||n))
    {
		sm=cnt=0;
		fg=1;

		rep(i,0,m)
		{
			scanf("%d",&tm[i].n);
			tm[i].ind=i+1;
		}
		sort(tm,tm+m,cmp);

		rep(i,0,n)
		{
			scanf("%d",&tb[i].n);
			tb[i].ind=i+1;
		}
		sort(tb,tb+n,cmp);

		rev(i,m-1,0)
		{
			mx=tm[i].n;
			int u=tm[i].ind;
			rev(j,n-1,0)
			{
				if(tb[j].n==0)
					continue;
				tb[j].n--;
				mx--;
				ve[u].push_back(tb[j].ind);
				if(mx==0)
					break;
			}
			sort(tb,tb+n,cmp);
			if(mx)
			{
				fg=0;
				break;
			}
		}
		if(!fg)
			printf("0\n");
		else
		{
			printf("1\n");
			FOR(i,1,m)
			{
				fg=1;
				l=ve[i].size();
				rep(j,0,l)
				{
					if(fg)
					{
						fg=0;
						printf("%d",ve[i][j]);
					}
					else
						printf(" %d",ve[i][j]);
				}
				puts("");
			}
		}
		for(i=1;i<=m;i++)
			ve[i].clear();
    }
    return 0;
}