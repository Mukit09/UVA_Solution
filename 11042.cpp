#include<stdio.h>

int main()
{
	long t,a,b;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		if(a<0)
			a=-a;
		if(b<0)
			b=-b;
		if(b==0)
			printf("1\n");
		else if(a==0)
			printf("2\n");
		else if(a==b)
			printf("4\n");
		else if(a!=b)
			printf("TOO COMPLICATED\n");
	}
	return 0;
}

