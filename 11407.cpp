#include<stdio.h>
#include<math.h>

long dp[10010],sqr[105];

long min(long a,long b)
{
	if(a<b)
		return a;
	return b;
}

long rec(long n) 
{
	if(n==0)
		return 0;
	if (dp[n] != -1)
	    return dp[n];
	long i=1,p;
	dp[n]=101;
	while(sqr[i]<=n) 
	{
		p=1+rec(n-sqr[i]);
	    dp[n]=min(dp[n],p);
	    i++;
	}
	return dp[n];
}

int main()
{
	long t,n,res,i;

	for(i=1;i<=101;i++)
		sqr[i]=i*i;

	for(i=1;i<=10000;i++)
		dp[i]=-1;

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		res=rec(n);
		printf("%ld\n",res);
	}
	return 0;
}