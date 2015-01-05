#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define si 100010
long long l,ll,a[si],n,i,j,cnt,mul,g_cd;

long long gcd(long long a,long long b)
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
	while(~scanf("%lld",&n)&&n)
	{
		l=cnt=0;
		ll=sqrt(n);
		for(i=1;i<=ll;i++)
		{
			if(n%i==0)
			{
				a[l++]=i;
				j=n/i;
				if(i!=j)
					a[l++]=n/i;
			}
		}
		sort(a,a+l);
		for(i=l-1;i>=0;i--)
		{
			for(j=i-1;j>=0;j--)
			{
				mul=a[i]*a[j];	
				if(mul<n)
					break;
				g_cd=gcd(a[i],a[j]);
				mul/=g_cd;
				if(mul%n==0)
					cnt++;
			}
		}
		printf("%lld %lld\n",n,cnt+1);
	}
	return 0;
}
