#include<stdio.h>

long i,j,k,a[110][110],mx,mx_sm,m,n,dp[110],s;
int main()
{
	while(~scanf("%ld%ld",&m,&n)&&(m||n))
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%ld",&a[i][j]);
		}

		mx=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				dp[j]=0;
			mx_sm=0;
			for(j=i;j<=m;j++)
			{
				mx_sm=0;
				for(k=1;k<=n;k++)
				{
					dp[k]+=(a[j][k]+1);
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