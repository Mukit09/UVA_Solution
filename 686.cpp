/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 627 (686 - Goldbach's Conjecture (II)) */
/* SUBMISSION: 09508232 */
/* SUBMISSION TIME: 2011-11-26 13:59:13 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<math.h>

int main()
{
	long n,i,k,j,flag,flag1,b;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0)
			break;
		if(n==4)
		{
			printf("1\n");
			continue;
		}
		k=0;
		for(i=3;i<=n/2;i+=2)
		{
			flag1=0;
			for(j=3;j<=sqrt(i);j+=2)
			{
				if(i%j==0)
				{
					flag1=1;
					break;
				}
			}
			if(flag1==1)
			{
				continue;
			}
			flag=0;
			b=n-i;
			for(j=3;j<=sqrt(b);j+=2)
			{
				if(b%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				k++;
			}
		}
		printf("%ld\n",k);
	}
	return 0;
}