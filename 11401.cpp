/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2396 (11401 - Triangle Counting) */
/* SUBMISSION: 09661759 */
/* SUBMISSION TIME: 2012-01-20 06:17:00 */
/* LANGUAGE: 1 */

#include<stdio.h>

long i,j,n;

long double a[1000001],add;

int main()
{
	a[3]=0;
	add=0;
	for(i=4;i<=1000000;i++)
	{
		add=add+(i-2)/2;
		a[i]=a[i-1]+add;
	}
	while(scanf("%ld",&n)&&n>=3)
	{
		printf("%.0llf\n",a[n]);
	}
	return 0;
}