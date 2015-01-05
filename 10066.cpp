#include<stdio.h>

long a1[110],a2[110],a[110][110];
long i,j,k=1,n,m;

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	while(~scanf("%ld%ld",&m,&n)&&(m||n))
	{
		for(i=0;i<m;i++)
			scanf("%ld",&a1[i]);
		for(i=0;i<n;i++)
			scanf("%ld",&a2[i]);

		printf("Twin Towers #%ld\n",k++);

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					a[i][j]=0;
				else if(a1[i-1]==a2[j-1])
					a[i][j]=a[i-1][j-1]+1;
				else
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		printf("Number of Tiles : %ld\n",a[m][n]);
		printf("\n");
	}
	return 0;
}