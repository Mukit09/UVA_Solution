#include<stdio.h>

long a[110][110];

int main()
{
	long t,n,i,j,k,x=1,e,max;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					a[i][j]=a[j][i]=0;
				else
					a[i][j]=a[j][i]=9999999;
			}
		}
		scanf("%ld",&e);
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&j,&k);
			a[j][k]=a[k][j]=1;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
		scanf("%ld%ld",&i,&j);
		max=0;
		for(k=0;k<n;k++)
			if(max<a[k][i]+a[k][j])
				max=a[k][i]+a[k][j];
		printf("Case %ld: %ld\n",x++,max);
	}
	return 0;
}