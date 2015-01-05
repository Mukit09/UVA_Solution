#include<stdio.h>
#include<math.h>
#define si 1000010

long dp[si];

long rec(long i)
{
	if(i==0)
		return 1;
	if(dp[i]!=-1)
		return dp[i];
	long p1,p2,p3;
	p1=rec(i-sqrt(i));
	p2=rec(log(i));
	p3=rec(i*sin(i)*sin(i));
	dp[i]=(p1+p2+p3)%1000000;
	return dp[i];
}

int main()
{
	long n,i,res;
	
	for(i=1;i<=1000000;i++)
		dp[i]=-1;
	dp[0]=1;
	for(i=1000000;i>=1;i--)
		res=rec(i);
	while(~scanf("%ld",&n))
	{
		if(n==-1)
			break;
		printf("%ld\n",dp[n]);
	}
	return 0;
}