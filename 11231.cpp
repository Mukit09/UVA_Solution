#include<stdio.h>

long n,m,c,a,re;

int main()
{
	while(scanf("%ld%ld%ld",&n,&m,&c)&&(n||m||c))
	{
		a=(n-7)*(m-7);
		re=a/2+(a%2)*c;
		printf("%ld\n",re);
	}
	return 0;
}