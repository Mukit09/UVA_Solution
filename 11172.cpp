/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2113 (11172 - Relational Operator) */
/* SUBMISSION: 08773599 */
/* SUBMISSION TIME: 2011-04-23 18:02:55 */
/* LANGUAGE: 3 */

#include<stdio.h>

int main()
{
long a,b,i,t;

scanf("%ld",&t);
for(i=1;i<=t;i++)
{
   scanf("%ld %ld",&a,&b);
   if(a>b)
	   printf(">\n");
   else if(a<b)
	   printf("<\n");
   else if(a==b)
	   printf("=\n");
}

return 0;
}