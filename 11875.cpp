/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2986 (11875 - Brick Game) */
/* SUBMISSION: 08853651 */
/* SUBMISSION TIME: 2011-05-17 01:42:46 */
/* LANGUAGE: 3 */

#include<stdio.h>
 int main()
 {
 long a[20],i,j,b,t,n;
scanf("%ld",&t);
for(i=1;i<=t;i++)
{
  scanf("%ld",&n);
  {
	  for(j=1;j<=n;j++)
{
		  scanf("%ld",&a[j]);
	  }
	b=j/2;
printf("Case %ld: %ld\n",i,a[b]);	
	  
  }
}
return 0;
 }