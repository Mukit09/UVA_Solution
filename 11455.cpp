/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2450 (11455 - Behold my quadrangle) */
/* SUBMISSION: 08878078 */
/* SUBMISSION TIME: 2011-05-23 17:40:37 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
long t,a,b,c,d,i,max;
scanf("%ld",&t);
for(i=1;i<=t;i++)
{
	scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
	if(a>b&&a>c&&a>d)
		max=a;
	else if(b>a&&b>c&&b>d)
		max=b;
	else if(c>a&&c>b&&c>d)
		max=c;
	else
		max=d;
if((a+b+c+d-max)>max)
{
if(a==b&&b==c&&c==d&&d==a)
printf("square\n");
else if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c))
printf("rectangle\n");
else
printf("quadrangle\n");;
}
else
printf("banana\n");
}
return 0;
}
