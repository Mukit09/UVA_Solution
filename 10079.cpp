/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1020 (10079 - Pizza Cutting) */
/* SUBMISSION: 09145559 */
/* SUBMISSION TIME: 2011-08-13 14:40:56 */
/* LANGUAGE: 3 */

#include<stdio.h>

int main()
{
	long double n,a,b,s;
	while(scanf("%llf",&n)!=EOF)
	{
		if(n<0)
			break;
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		a=n+1;
		b=(double)n/2;
		s=a*b;
		printf("%.0llf\n",s+1);
	}
	return 0;
}