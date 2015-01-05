#include<stdio.h>
#include<math.h>

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

long min(long a,long b)
{
	if(a<b) return a;
	else return b;
}

long i,j,k,cost,w[110][110],n,r,u,v,t=1;
double cst;
int main()
{
	while(~scanf("%ld%ld",&n,&r)&&(n||r))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				w[i][j]=0;
		}
		for(i=1;i<=r;i++)
		{
			scanf("%ld%ld%ld",&u,&v,&cost);
			w[u][v]=w[v][u]=cost;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));
				}
			}
		}
		scanf("%ld%ld%ld",&u,&v,&cost);
		printf("Scenario #%ld\n",t++);
		cst=w[u][v]-1;
		cst=ceil(cost/cst);
		printf("Minimum Number of Trips = %.0lf\n\n",cst);
	}
	return 0;
}