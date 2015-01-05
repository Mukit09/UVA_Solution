#include<stdio.h>

long i,j,k,t,n,b,a[110][110],x1,x2,y1,y2,dp[110],mx,mx_sm;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&b);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				a[i][j]=1;
		}
		for(k=1;k<=b;k++)
		{
			scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=y2;j++)
					a[i][j]=0;
			}
		}

		mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				dp[j]=0;
			for(j=i;j<=n;j++)
			{
				mx_sm=0;
				for(k=1;k<=n;k++)
				{
					dp[k]+=a[j][k];
					if(dp[k]==j-i+1)
						mx_sm+=dp[k];
					else
						mx_sm=0;
					if(mx_sm>mx)
						mx=mx_sm;
				}
			}
		}
		printf("%ld\n",mx);
	}
	return 0;
}