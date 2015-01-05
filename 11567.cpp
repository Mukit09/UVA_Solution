#include<stdio.h>

long long min(long long a,long long b)
{
	return (a<b)?a:b;
}

long long rec(long long a)
{
	if(a==1)
		return 1;
	else if(a==0)
		return 0;
	else if(a&1) // & operator check kore a er binary te most right e 1 ache kina... 1 thakle 1 return kore na hoi 0
		return 1+min(rec(a+1),rec(a-1)); // orthat,ekhane bijor kina check kora hocche...
	else
		return 1+rec(a/2);
}

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		printf("%lld\n",rec(n));
	}
	return 0;
}