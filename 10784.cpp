/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1725 (10784 - Diagonal) */
/* SUBMISSION: 09506971 */
/* SUBMISSION TIME: 2011-11-26 05:31:45 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<math.h>

int main()
{
	long n,a,i=1;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0)
			break;
		a=ceil((3+sqrt(9+8*n))/2);
		printf("Case %ld: %ld\n",i++,a);

	}
	return 0;
}