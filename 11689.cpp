/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2736 (11689 - Soda Surpler) */
/* SUBMISSION: 08883218 */
/* SUBMISSION TIME: 2011-05-25 06:00:26 */
/* LANGUAGE: 1 */

#include<stdio.h>
int main()
{
long n,e,f,c,a,i,g,h,m;
scanf("%ld\n",&n);
for(i=1;i<=n;i++)
{
scanf("%ld%ld%ld",&e,&f,&c);
a=e+f;
m=0;

while(a>=c)
{
g=a%c;
h=a/c;
a=g+h;
m+=h;	
}
printf("%ld\n",m);
}
return 0;
}