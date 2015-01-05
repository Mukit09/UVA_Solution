#include<stdio.h>

double t,a,b,c,per_time,x,tk;
int main()
{
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		per_time=(a+b)/3;
		x=a-per_time;
		tk=(c*x)/per_time;
		printf("%.0lf\n",tk);
	}
	return 0;
}