/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1176 (10235 - Simply Emirp) */
/* SUBMISSION: 09466976 */
/* SUBMISSION TIME: 2011-11-13 05:11:58 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<math.h>

int main()
{
	long n,i,sum,flag,m,b,flag1;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==19)
		{
			printf("19 is prime.\n");
			continue;
		}
		flag=0;
		if(n==1||n==2||n==3)
		{
			continue;
		}
		else if(n%2==0)
		{
			flag=1;
		}
		else
		{
			for(i=3;i<=sqrt(n);i+=2)
			{
				if(n%i==0)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		{
			printf("%ld is not prime.\n",n);
		}
		else
		{
			flag1=0;
			sum=0;
			m=n;
			while(m!=0)
			{
				b=m%10;
				sum=sum*10+b;
				m=m/10;
			}
			if(sum==n)
			{
				flag1=1;
			}
			else
			{
				if(sum==1||sum==2||sum==3)
				{
					continue;
				}
				else if(sum%2==0)
				{
					flag1=1;
				}
				else
				{
					for(i=3;i<=sqrt(sum);i+=2)
					{
						if(sum%i==0)
						{
							flag1=1;
							break;
						}
					}
				}
			}
			if(flag1==0)
			{
				printf("%ld is emirp.\n",n);
			}
			else
			{
				printf("%ld is prime.\n",n);
			}
		}
	}
	return 0;
}