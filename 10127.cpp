#include<stdio.h>

int main()
{
	long b,cnt,a,n;
	while(~scanf("%ld",&n))
	{
		a=b=1;
		cnt=0;
		while(a)
		{
			a=b%n;
			b=a*10+1;
			cnt++;
		}
		printf("%ld\n",cnt);
	}
	return 0;
}