#include<stdio.h>

int main()
{
	 long sm1,sm2,t,a,b,c,d,n,s,real_start,real_end,x=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		sm1=a+b+1;
		sm2=c+d+1;
		real_start=a+1;
		real_end=sm2-c-1;
		n=sm2-(sm1-1);
		s=(n*(2*sm1+(n-1)))/2;
		printf("Case %lld: %lld\n",x++,s-real_start-real_end);
	}
	return 0;
}