/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2412 (11417 - GCD) */
/* SUBMISSION: 08773695 */
/* SUBMISSION TIME: 2011-04-23 18:35:54 */
/* LANGUAGE: 3 */

#include<stdio.h>
long GCD(long a,long b)
{
	long x;
	while(b!=0)
	{
		x=a%b;
		a=b;
		b=x;
	}
	return a;
}
int main()
{
  long g,i,j,n;
while(scanf("%ld",&n)!=EOF)
{
	if(n==0)
		break;
   g=0;
     for(i=1;i<n;i++)
     for(j=i+1;j<=n;j++)
	{
        g+=GCD(i,j);
	}
printf("%ld\n",g);
}
return 0;
}