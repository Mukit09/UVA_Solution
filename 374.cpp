/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 310 (374 - Big Mod) */
/* SUBMISSION: 09190975 */
/* SUBMISSION TIME: 2011-08-25 15:20:26 */
/* LANGUAGE: 3 */

#include<stdio.h>

long square(long s)
{
	return s*s;
}

long bigmod(long b,long p,long m)
{
	if(p==1)
	{
		return b;
	}
	else if(p%2==0)
	{
		return square(bigmod(b,p/2,m))%m;
	}
	else
	{
		return ((b%m)*bigmod(b,p-1,m))%m;
	}
}

int main()
{
	long b,p,m,sum;

	while(scanf("%ld%ld%ld",&b,&p,&m)!=EOF)
	{
		sum=bigmod(b,p,m);
		printf("%ld\n",sum);
	}
	return 0;
}
