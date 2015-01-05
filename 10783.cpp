/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1724 (10783 - Odd Sum) */
/* SUBMISSION: 08773657 */
/* SUBMISSION TIME: 2011-04-23 18:21:56 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
long sum,i,j,t,a,b;
scanf("%ld",&t);
for(i=1;i<=t;i++)
{
	scanf("%ld%ld",&a,&b);
	sum=0;
	for(j=a;j<=b;j++)
	if((j%2)!=0)
		sum+=j;
	printf("Case %ld: %ld\n",i,sum);
}
return 0;
}