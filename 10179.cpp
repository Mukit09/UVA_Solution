#include<stdio.h>

long phi(long n)
{
	long i,output;
	if(n==1)
	    return 1;
 
	output=n;
	if(n%2==0) 
	{
	    output-=(output/2);
	    while(n%2==0)
	        n/=2;
	}
	for(i=3;i*i<=n;i+=2)
	{
	    if(n%i==0)
		{
	        output-=(output/i);
	        while(n%i==0)
	           n/=i;
	    }
	}
	if(n>1)
	    output-=(output/n);
	return output;
}
	 
int main ()
{
	long n;
	while(~scanf("%ld",&n)&&n)
	{
	    printf("%ld\n",phi(n));
    }
	 
    return 0;
}