#include<stdio.h>
#include<math.h>

int main()
{
	long n;
	double b,digit,a;
	while(scanf("%ld",&n)==1)
	{
		digit=floor((n*log10(2))+1);
		a=digit/(log10(2))-n;
		b=pow(2,a);

		printf("2^-%ld = %.3lfe-%.0lf\n",n,b,digit);
	}
	return 0;
}