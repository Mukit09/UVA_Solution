#include<stdio.h>

int main()
{
	double n,a,x;
	while(scanf("%lf",&n)&&n)
	{
		a=1;
		while(1)
		{
			a++;
			if(a*a*a>n)
			{
				a--;
				break;
			}
		}
		x=(n-a*a*a)/(3*a*a);
		printf("%.4lf\n",a+x);
	}
	return 0;
}