#include <stdio.h>
#include <math.h>
 
#define EPS 1e-7
 
int p,q,r,s,t,u;
 
double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x + u;
}
 
double bisection()
{
	double low=0,high=1,x;
	while(low+EPS<high)
	{
		x=(low+high)/2.00;
		if(f(low)*f(x)<=0)
			high=x;
		else 
			low=x;
	}
	return (low+high)/2.00;
}
 
int main()
{
	double x,y;
	while(scanf("%ld%ld%ld%ld%ld%ld",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		x=f(0);
		y=f(1);
		if(x*y>0)
			puts("No solution");
		else 
		{
			if(x==0)
				printf("0.0000\n");
			else if(y==0)
				printf("1.0000\n");
			else
				printf("%.4lf\n",bisection());
		}
	}
	return 0;
}