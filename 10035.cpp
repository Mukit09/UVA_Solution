/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 976 (10035 - Primary Arithmetic) */
/* SUBMISSION: 08773416 */
/* SUBMISSION TIME: 2011-04-23 16:39:15 */
/* LANGUAGE: 3 */

#include<stdio.h>

int main()
{
  long a,b,i,k,x,y,z,c;
    while(scanf("%ld%ld",&a,&b)!=EOF)
	{
	if(a==0&&b==0)
	break;
	k=0;
    c=0;
	for(i=1;i<=10;i++)
	{
	
	x=a%10;
	y=b%10;
	z=x+y+c;
	
	if(z>9)
        k++;
	a/=10;
	b/=10;
	if(a==0&&b==0)
		break;
	
	if(z>9)
		c=1;
	else c=0;
	
	}
	if(k==1)
	printf("%ld carry operation.\n",k);
	else if(k==0)
		printf("No carry operation.\n");
	else
		printf("%ld carry operations.\n",k);
	}
	return 0;

}
