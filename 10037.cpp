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

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define FOR1(i,a,b) for(i=a;i<=b;i++)
#define FOR0(i,a,b) for(i=a;i<b;i++)
#define REV(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,sm,cnt,fg,a[si],res[si],cnt1,cnt2,chk1,chk2;
char ch[si];

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
	int t;
	scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&n);
		sm=cnt=0;
		fg=1;
		FOR0(i,0,n)
		{
			scanf("%d",&a[i]);
			res[i]=0;
		}
		if(n<=2)
		{
			sm=a[n-1];
			printf("%d\n",sm);
			FOR0(i,0,n)
			{
				if(!i)
					printf("%d",a[0]);
				else
					printf(" %d",a[i]);
			}
			puts("");
			goto end;
		}
		sort(a,a+n);
		cnt1=a[0]+2*a[1];
		cnt2=2*a[0];
		if(n%2==0)
		{
			for(i=n-1;i>=2;i-=2)
			{
				chk1=(cnt1+a[i]);
				chk2=(cnt2+a[i]+a[i-1]);
				if(chk1<chk2)
				{
					res[i]=1;
					sm+=chk1;
				}
				else
				{
					res[i]=2;
					sm+=chk2;
				}
			}
			sm+=a[1];
			printf("%d\n",sm);
			for(i=n-1;i>=2;i-=2)
			{
				if(res[i]==1)
				{
					printf("%d %d\n",a[0],a[1]);
					printf("%d\n",a[0]);
					printf("%d %d\n",a[i-1],a[i]);
					printf("%d\n",a[1]);
				}
				else
				{
					printf("%d %d\n",a[0],a[i]);
					printf("%d\n",a[0]);
					printf("%d %d\n",a[0],a[i-1]);
					printf("%d\n",a[0]);
				}
			}
			printf("%d %d\n",a[0],a[1]);
		}
		else
		{
			for(i=n-1;i>=3;i-=2)
			{
				chk1=cnt1+a[i];
				chk2=(cnt2+a[i]+a[i-1]);
				if(chk1<chk2)
				{
					res[i]=1;
					sm+=chk1;
				}
				else
				{
					res[i]=2;
					sm+=chk2;
				}
			}
			sm+=(cnt1+a[2]);
			sm-=a[1];
			printf("%d\n",sm);
			for(i=n-1;i>=3;i-=2)
			{
				if(res[i]==1)
				{
					printf("%d %d\n",a[0],a[1]);
					printf("%d\n",a[0]);
					printf("%d %d\n",a[i-1],a[i]);
					printf("%d\n",a[1]);
				}
				else
				{
					printf("%d %d\n",a[0],a[i]);
					printf("%d\n",a[0]);
					printf("%d %d\n",a[0],a[i-1]);
					printf("%d\n",a[0]);
				}
			}
			printf("%d %d\n",a[0],a[1]);
			printf("%d\n",a[0]);
			printf("%d %d\n",a[0],a[2]);
		}
end:
		if(t)
			puts("");
    }
    return 0;
}