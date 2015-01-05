#include<stdio.h>
#include<math.h>

int main()
{
	long long n,i,sq;
	while(scanf("%lld",&n)&&n>=0)
	{
		i=2;
		while(1)
		{
			if(n%i==0)
			{
				printf("    %lld\n",i);
				n/=i;
			}
			else
				break;
		}
		sq=sqrt(n);
		i=3;
		while(1)
		{
			if(n%i==0)
			{
				printf("    %lld\n",i);
				n/=i;
			}
			else if(i>sqrt(n))
			{
				printf("    %lld\n",n);
				break;
			}
			else
				i+=2;
			if(i>n)
				break;
			
		}
		printf("\n");
	}
	return 0;
}