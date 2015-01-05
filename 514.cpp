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

//typedef __int64 i64;

int i,j,l,n,x=1,sm,cnt,fg,a[si];
stack<int>stk;

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
    while(~scanf("%d",&n)&&n)
    {
		while(1)
		{
			scanf("%d",&a[1]);
			if(a[1]==0)
				break;
			FOR1(i,2,n)
				scanf("%d",&a[i]);
			j=1;
			int k;
			FOR1(k,1,n)
			{
				stk.push(k);
				int nw=k;
				if(nw==a[j])
				{
					while(a[j]==nw)
					{
						stk.pop();
						j++;
						if(!stk.empty())
							nw=stk.top();
						else
							break;
					}
				}
			}
			if(j>n)
				puts("Yes");
			else
				puts("No");
			while(!stk.empty())
				stk.pop();
		}
		puts("");
    }
    return 0;
}