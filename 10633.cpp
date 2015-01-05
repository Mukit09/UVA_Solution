/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1574 (10633 - Rare Easy Problem) */
/* SUBMISSION: 09618916 */
/* SUBMISSION TIME: 2012-01-05 04:09:53 */
/* LANGUAGE: 1 */

#include<stdio.h>
 
int main()
{
	long long x,y,z,n;
 
	while(scanf("%lld",&y)!=EOF)
	{
		 if(y==0)
		 {
			break;
		 }
 
		 x=y/9;
		 n=y+x;	
 
		 z=x*9;
		 if(z==y)
		 {
			printf("%lld ",n-1);
		 }
		 printf("%lld\n",n);
	}
 
	return 0;
}