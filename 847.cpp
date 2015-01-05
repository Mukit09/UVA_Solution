#include<stdio.h>
long n,p,stan;

int main()
{
	while(~scanf("%ld",&n))
	{
		p=stan=1;
		while(p<n)
		{
			if(stan)
			{
				p*=9;
				stan=0;
			}
			else
			{
				p*=2;
				stan=1;
			}
		}
		if(!stan)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return 0;
}