#include<stdio.h>

long i,j,k,a[1010][1010],mx,mx_sm,m,n,dp[1010],l,fg=0;
int main()
{
	while(~scanf("%lld%lld",&n,&m)&&(n||m))
	{
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=n;j++)
				scanf("%lld",&a[i][j]);
		}

		
		if(fg)
			printf("\n");
		fg=1;
		mx=0;
		for(i=n;i>=m;i--)
		{
			for(j=1;j<=n;j++)
				dp[j]=0;

			for(j=i;j>=n-m+1;j--)
			{
				mx_sm=0;
				for(k=1;k<=n-m+1;k++)
				{	
					dp[k]+=a[j][k];
					mx_sm+=dp[k];
				}
				
				
			}
			mx+=mx_sm;
			printf("%lld\n",mx_sm);
		}
		printf("%lld\n",mx);
	}
	return 0;
}