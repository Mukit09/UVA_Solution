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

double l,sm,fg,a[si],m,av;
int i,j,x=1,n,cnt,k;
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
    while(~scanf("%lf%d",&m,&n))
    {
		fg=1;
		sm=0;
		FOR0(i,0,n)
		{
			scanf("%lf",&a[i]);
			sm+=a[i];
		}
		av=sm/m;
		sort(a,a+n);
		double imb=0;
		cnt=(int)m;
		j=n-1;
		k=0;
		printf("Set #%d\n",x++);
		FOR0(i,0,m)
		{
			if(cnt*2>n&&fg)
			{
				printf(" %d: %.0lf\n",i,a[j]);
				imb+=fabs(av-a[j--]);
				if(j<0)
					fg=0;
				cnt--,n--;
			}
			else if(cnt*2==n&&fg)
			{
				printf(" %d: %.0lf %.0lf\n",i,a[j],a[k]);
				imb+=fabs(av-(a[j--]+a[k++]));
				cnt--;
				n-=2;
			}
			else
			{
				imb+=av;
				printf(" %d:\n",i);
			}
		}
		printf("IMBALANCE = %.5lf\n\n",imb);
    }
    return 0;
}