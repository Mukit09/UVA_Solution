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
#define si 110
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

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,x=1,cnt,sm,fg,lr[si],rl[si],k,found,q;
char ch[105][5];

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

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d",&n))
   	{
		found=0;
		j=1;
		k=9999;
		rep(i,0,n)
		{
			scanf("%s",ch[i]);
			if(strcmp(ch[i],"?")==0)
			{
			    if(found)
                lr[i]=k++;
			    else
                lr[i]=9999;
			}
			else
			{
			    found=1;
                k=1;
                lr[i]=9999;
			}
		}
		k=1;found=0;
		rev(i,n-1,0)
		{
		    if(strcmp(ch[i],"?")==0)
			{
			    if(found)
			    rl[i]=k++;
			    else
			    rl[i]=9999;
			}
			else
			{
                k=1;
                found=1;
                rl[i]=9999;
			}
		}
		scanf("%d",&q);
		while(q--)
		{
		    scanf("%d",&j);
		    j--;
		    if(lr[j]<rl[j])
		    {
		        fr(i,1,lr[j])
		        printf("right of ");
		        rev(i,j,0)
		        {
		            if(strcmp(ch[i],"?")!=0)
		            {
		                puts(ch[i]);
		                break;
		            }
		        }
		    }
		    else if(lr[j]>rl[j])
		    {
		        fr(i,1,rl[j])
		        printf("left of ");
		        fr(i,j,n-1)
		        {
		            if(strcmp(ch[i],"?")!=0)
		            {
		                puts(ch[i]);
		                break;
		            }
		        }
		    }
		    else if(lr[j]==rl[j]&&lr[j]!=9999)
		    {
		        printf("middle of ");
		        rev(i,j,0)
		        {
		            if(strcmp(ch[i],"?")!=0)
		            {
		                printf("%s ",ch[i]);
		                break;
		            }
		        }
		        rep(i,j,n-1)
		        {
		            if(strcmp(ch[i],"?")!=0)
		            {
		                printf("and %s\n",ch[i]);
		                break;
		            }
		        }
		    }
		    else
		    puts(ch[j]);
		}
    }
   	return 0;
}
