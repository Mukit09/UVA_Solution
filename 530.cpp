/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 471 (530 - Binomial Showdown) */
/* SUBMISSION: 09270719 */
/* SUBMISSION TIME: 2011-09-17 19:03:42 */
/* LANGUAGE: 3 */

#include<stdio.h>

int main()
{
	long double a,b,n,r,i;
	while(scanf("%llf%llf",&n,&r)!=EOF)
	{
		if(n==0&&r==0)
			break;
		a=1;
		b=1;
		if(r>(n-r))
		{
			for(i=(r+1);i<=n;i++)
			{
				a=a*i;
			}
			for(i=1;i<=n-r;i++)
			{
				b=b*i;
			}
		}
		else
		{
			for(i=(n-r+1);i<=n;i++)
			{
				a=a*i;
			}
			for(i=1;i<=r;i++)
			{
				b=b*i;
			}
		}
		printf("%.0llf\n",(a/b));
	}
}