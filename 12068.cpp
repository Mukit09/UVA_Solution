#include<stdio.h>

long GCD(long a,long b)
{

	long x;
	while(b!=0)
	{
		x=a%b;

		a=b;
		b=x;
	}
	return a;
}

int main()
{
	long t,i,n,a[15],sum,b,j,d,e;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		b=1;
		sum=0;
		scanf("%ld",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&a[j]);
			b=b*a[j];
		}
		for(j=1;j<=n;j++)
		{
			sum=sum+b/a[j];
		}
		d=b*n;
		e=GCD(d,sum);
		d=d/e;
		sum=sum/e;
		printf("Case %ld: %ld/%ld\n",i,d,sum);
	}
	return 0;
}