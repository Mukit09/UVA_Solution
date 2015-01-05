#include<stdio.h>
  
long weight[1000],n,mx,dp[50][210];

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

long rec(long i,long w)
{
	long p1,p2;
	if(i>n)
		return 0;
	if(dp[i][w]!=-1)
		return dp[i][w];
	if(w+weight[i]<=mx)
		p1=weight[i]+rec(i+1,w+weight[i]);
	else
		p1=0;
	p2=rec(i+1,w);
	dp[i][w]=max(p1,p2);
	return dp[i][w];
}
  
int main()
{
    long i,t,sum,j,m;
	char ch;
	scanf("%ld",&t);
    while(t--)
	{
		for(i=1;;i++)
		{
			scanf("%ld%c",&weight[i],&ch);
			if(ch!=' ')
				break;
		}
		n=i;
		sum=0;
		for(i=1;i<=n;i++)
			sum+=weight[i];
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=sum;j++)
				dp[i][j]=-1;
		}
		mx=sum/2;
		m=2*rec(1,0);
		if(m==sum)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;

}
