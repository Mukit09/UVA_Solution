#include<stdio.h>
int main()
{
	long a,b;
	while(scanf("%ld %ld",&a,&b)!=EOF)
		printf("%ld\n",(a*b)-1);
	return 0;
}