

/*
REAL CODE niche CHORA CODE

#include<stdio.h>

int main()
{
	long step,x,c,mod;
	while(scanf("%ld%ld",&step,&mod)==2)
	{
		x=c=0;
		x=(x+step)%mod;
		while(x)
		{
			c++;
			x=(x+step)%mod;
		}
		if(c==mod-1)
			printf("%10ld%10ld    Good Choice\n\n",step,mod);
		else
			printf("%10ld%10ld    Bad Choice\n\n",step,mod);
	}
	return 0;
}

  erporei chora code,run time kom
*/

#include<stdio.h>

long gcd(long a,long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	long a,b,n;
	while(scanf("%ld%ld",&a,&b)==2)
	{
		n=gcd(a,b);
		if(n==1)
			printf("%10ld%10ld    Good Choice\n\n",a,b);
		else
			printf("%10ld%10ld    Bad Choice\n\n",a,b);
	}
	return 0;
}