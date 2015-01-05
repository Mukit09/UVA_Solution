
/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1287 (10346 - Peter's Smokes) */
/* SUBMISSION: 08897364 */
/* SUBMISSION TIME: 2011-05-28 19:01:45 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
	long n,a,b,c,d,k,m;
	while(scanf("%ld%ld",&n,&k)!=EOF)
	{
	  d=0;
	  a=n/k;
	  b=n%k;
	  c=a+b;
	  m=n;
	  while(a!=0)
	  {
	    a=n/k;
		b=n%k;
		c=a+b;
		n=c;
        d+=a;
	  }
	  printf("%ld\n",d+m);
	}
	return 0;
}