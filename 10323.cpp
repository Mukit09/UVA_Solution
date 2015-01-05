
#include<stdio.h>
int main()
{
	long n,i,a;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n<0)
		{
			if(n%2==0)
           		printf("Underflow!\n");
			else
				printf("Overflow!\n");
		}

		if(n>13)
			printf("Overflow!\n");
		else if(n<8&&n>=0)
			printf("Underflow!\n");
		else if(n<14&&n>7)
		{
			a=1; 
			for(i=1;i<=n;i++)
				a=a*i;
			printf("%ld\n",a);
		}
	}
	return 0;
}