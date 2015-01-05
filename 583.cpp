/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 524 (583 - Prime Factors) */
/* SUBMISSION: 09541884 */
/* SUBMISSION TIME: 2011-12-08 03:17:21 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<math.h>

int main()
{
	long n,i,j,p,a[1000],flag;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0)
			break;
		if(n<0)
			p=-n;
		else
			p=n;
		for(j=1;;j++)
		{
			flag=0;
			if(p%2==0)
			{
				a[j]=2;
				p=p/2;
			}
			else
			{
				for(i=3;i<=sqrt(p);i+=2)
				{
					if(p%i==0)
					{
						a[j]=i;
						p=p/i;
						flag=1;
						break;
					}	
				}
				if(flag!=1)
				{
					a[j]=p;
					p=1;
				}
			}
			if(p==1)
				break;
		}
		if(n<0)
		{
			printf("%ld = -1",n);
			for(i=1;i<=j;i++)
			{
				printf(" x %ld",a[i]);
			}
		}
		else
		{
			printf("%ld = %ld",n,a[1]);
			for(i=2;i<=j;i++)
			{
				printf(" x %ld",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}