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
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,cnt,sm,fg,a[30],mat[30][30];
char ch[si];
map<int,int>mp;
vector<int>ve;

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

int main()
{
	int u,v,e,k;
   	while(~scanf("%d%d",&n,&e))
	{
		scanf("%s",ch);
		l=strlen(ch);
		
		FOR(i,1,n)
		{
			a[i]=0;
			FOR(j,1,n)
				mat[i][j]=0;
		}
		cnt=0;
		k=1;
		rep(i,0,l)
		{
			mp[ch[i]-64]=k++;
			a[mp[ch[i]-64]]=3;
			cnt++;
		}
		while(e--)
		{
			scanf("%s",ch);
			int ck1,ck2;
			ck1=mp[ch[0]-64];
			ck2=mp[ch[1]-64];
			if(!ck1)
				mp[ch[0]-64]=k++;
			if(!ck2)
				mp[ch[1]-64]=k++;
			u=mp[ch[0]-64];
			v=mp[ch[1]-64];
			mat[u][v]=mat[v][u]=1;
		}
		int ans=0;
		while(1)
		{
			fg=0;
			FOR(i,1,n)
			{
				if(!a[i])
				{
					int sm=0;
					FOR(j,1,n)
					{
						if(mat[i][j]==1&&a[j]>=3)
						{
							sm++;
							if(sm==3)
							{
								fg=1;
								cnt++;
								ve.push_back(i);
								break;
							}
						}
					}
				}
			}
			if(!fg)
				break;
			ans++;
			int l=ve.size();
			rep(i,0,l)
			{
				u=ve[i];
				a[u]=3;
			}
			ve.clear();
		}
		if(cnt==n)
			printf("WAKE UP IN, %d, YEARS\n",ans);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
		mp.clear();
		ve.clear();
    }
   	return 0;
}