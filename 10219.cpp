#include<stdio.h>
#include<math.h>

int main()
{
	long long i,n,k;
	long double ans;
	while(~scanf("%lld%lld",&n,&k))
	{
		ans=0;
		for(i=n;i>n-k;i--)
			ans+=log10(i);
		for(i=1;i<=k;i++)
			ans-=log10(i);
		printf("%ld\n",(long)floor(ans)+1);
	}
	return 0;
}