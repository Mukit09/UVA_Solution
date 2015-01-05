/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2724 (11677 - Alarm Clock) */
/* SUBMISSION: 08773887 */
/* SUBMISSION TIME: 2011-04-23 19:46:37 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
long h,m,a,b,i,n,q,s;
while(scanf("%ld%ld%ld%ld",&h,&m,&a,&b)!=EOF)
{
if(h==0&&m==0&&a==0&&b==0)
break;
n=h*60+m;
q=a*60+b;
if(n>q)
{s=24*60-(n-q);
printf("%ld\n",s);}
else
{s=(q-n);
printf("%ld\n",s);}
}
return 0;
}