/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 429 (488 - Triangle Wave) */
/* SUBMISSION: 09203557 */
/* SUBMISSION TIME: 2011-08-29 19:31:09 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<string.h>

int main()
{
	long i,j,k,m,a,b,t;
	scanf("%ld",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%ld%ld",&a,&b);
		for(m=1;m<=b;m++)
		{
			for(i=1;i<=a;i++)
			{
				for(j=1;j<=i;j++)
				{
					printf("%ld",i);
				}
				printf("\n");
			}
			for(i=a-1;i>=1;i--)
			{
				for(j=1;j<=i;j++)
				{
					printf("%ld",i);
				}	
				printf("\n");
			}
			if(m!=b)
			printf("\n");
		}
		if(k!=t)
		printf("\n");
	}
	return 0;
}