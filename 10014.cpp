#include<stdio.h>

int main()
{
	long t,i,n;
	double af,al,c,sum;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%lf%lf",&n,&af,&al);
		sum=af*n+al;
		for(i=n;i>=1;i--)
		{
			scanf("%lf",&c);
			sum-=2*c*i;
		}
		sum/=(n+1);
		printf("%.2lf\n",sum);
		if(t)
			printf("\n");
	}
	return 0;
}