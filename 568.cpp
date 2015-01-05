/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 509 (568 - Just the Facts) */
/* SUBMISSION: 09667173 */
/* SUBMISSION TIME: 2012-01-22 09:34:25 */
/* LANGUAGE: 1 */

#include <stdio.h>

int main()
{
	long n,i,a;
    while(scanf("%ld",&n)==1)
    {
		a=1;
		for (i=1;i<=n;i++)
        {
			a=a*i;
            while(a%10==0)
            {
				a/=10;
			}
			a=a%100000;
		}
		printf("%5ld -> %ld\n",n,a%10);
	}
	return 0;
}