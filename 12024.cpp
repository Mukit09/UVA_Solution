#include<stdio.h>

int main()
{
	long i,j,n;
	long double a[14];
	a[0]=a[1]=1;
	for(i=2;i<=12;i++)
	{
		a[i]=a[i-1]*i;
	}
	long double t,result;
	scanf("%llf",&t);
	while(t--)
	{
		scanf("%ld",&n);
		result=0;
		for(i=3,j=2;i<=n||j<=n;i+=2,j+=2)
		{
			if(j<=n)
			{
				result=result+(double)(1/a[j]);
			}
			if(i<=n)
			{
				result=result-(double)(1/a[i]);
			}
		}
		result*=a[n];
		printf("%.0llf/%.0llf\n",result,a[n]);
	}
	return 0;
}