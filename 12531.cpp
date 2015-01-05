#include<stdio.h>

int main()
{
	long n;
	while(~scanf("%ld",&n))
	{
		if(n%6==0)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}