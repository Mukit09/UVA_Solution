#include<stdio.h>
#include<math.h>

double x[210],y[210],a[210][210];
long n,i,j,k,t=1;

double min(double a,double b)
{
	if(a<b) return a;
	else return b;
}

double max(double a,double b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					a[i][j]=0;
				else
					a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
				}
			}
		}
		printf("Scenario #%ld\n",t++);
		printf("Frog Distance = %.3lf\n",a[1][2]);
		printf("\n");
	}
	return 0;
}