#include<stdio.h>
#define inf -9999999

long n,t,i,j,k,mx,mx_sm,m,dp[180],a[180][180],s,l;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%ld",&a[i][j]);
		}
		m=n+n-1;
		for(i=1;i<=m;i++)
		{
			for(j=n+1;j<=m;j++)
			{
				a[i][j]=a[i][j-n];
				a[j][i]=a[j-n][i];
				a[j][j]=a[j-n][j-n];
			}
		}
		mx=inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=m;k++)
					dp[k]=0;
				for(k=i;k<=i+n-1;k++)
				{
					s=0;
					mx_sm=inf;
					for(l=j;l<=j+n-1;l++)
					{
						dp[l]+=a[k][l];
						s+=dp[l];
						if(s>mx_sm)
							mx_sm=s;
						if(s<0)
							s=0;
					}	
					if(mx<mx_sm)
						mx=mx_sm;
				}
			}
		}
		printf("%ld\n",mx);
	}
	return 0;
}
