#include<stdio.h>
#include<math.h>
long t,n,i,l,ll,flag;
long sum_dig(long n)
{
	long sum=0;
	while(n)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}
long sum_pf(long n)
{
	long sum=0,i;
	while(n%2==0)
	{
		sum+=2;
		n/=2;
		flag=1;
	}
	for(i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			sum+=sum_dig(i);
			n/=i;
			flag=1;
		}
	}
	if(n>1)
		sum+=sum_dig(n);
	return sum;
}
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=n+1;i<=1000000165;i++)
		{
			flag=0;
			l=sum_pf(i);
			ll=sum_dig(i);
			if(l==ll&&flag&&i!=2)
				break;
		}
		printf("%ld\n",i);
	}
	return 0;
}
