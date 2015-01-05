#include<stdio.h>
int main()
{
	double a,b,n,cel,i,fer,c,d;
	scanf("%lf",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf %lf",&cel,&fer);
	a=fer*5;
	b=a/9;
	c=b+cel;
	printf("Case %.0lf: %.2lf\n",i,c);
	}
	return 0;
}