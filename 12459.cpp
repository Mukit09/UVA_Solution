#include<stdio.h>

long long dp[1010];

long long fibo(long long k)
{
	if(k==0||k==1)
		return 1;
	if(dp[k]!=-1)
		return dp[k];
	 dp[k]=fibo(k-1)+fibo(k-2);
	 return dp[k];
}

int main()
{
	long long n,sum,i;
	while(~scanf("%lld",&n)&&n)
	{
    	for(i=1;i<=n;i++)
	    	dp[i]=-1;
	     sum=fibo(n);
	     printf("%lld\n",sum);
      }
	return 0;
}
