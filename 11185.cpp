/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2126 (11185 - Ternary) */
/* SUBMISSION: 08875156 */
/* SUBMISSION TIME: 2011-05-23 04:58:54 */
/* LANGUAGE: 3 */

#include<stdio.h>
long n,a,b[1000000],i,j;
int main()
{
while(scanf("%ld",&n)!=EOF)

{
if(n<0)
break;
else
if(n==0)
{
	printf("0\n");

	continue;
}

 a=n;i=0;
while(a!=0)
{
 b[i]=a%3;
 a=a/3;
 i++;
}
for(j=i-1;j>=0;j--)
 printf("%ld",b[j]);
 printf("\n");
}
return 0;
}