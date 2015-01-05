#include<stdio.h>

double comb(double j,double k)
{
	double i,a=1;
	for(i=j;i<=k;i++)
		a*=i;
	return a;
}

int main()
{
	double n,a,b,c,fg=0;
	while(~scanf("%lf",&n))
	{
		a=comb(1,n);
		b=comb(n+1,2*n);
		c=(b/a);
		c/=(n+1);
		if(fg)
			printf("\n");
		fg=1;
		printf("%.0lf\n",c);
	}
	return 0;
}