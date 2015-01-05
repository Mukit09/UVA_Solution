#include<stdio.h>
#include<math.h>
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define si 100000010
#define si_pr 6000000

int ara[si/32],ll=1,pr[si_pr];

int check(int m,int pos)
{
	return (m&(1<<pos));
}

int set(int m,int pos)
{
	return (m|(1<<pos));
}

void sieve()
{
	int i,j,num=si-5,root=sqrt(num);
	pr[ll++]=2;
	ara[0/32]=ara[1/32]=1;
	for(i=3;i<=num;i+=2)
	{
		if(check(ara[i>>5],i&31)==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j>>5]=set(ara[j>>5],j&31);
			}
		}
	}
}

int main()
{
	int l,h,i,j,k,fg,nn,m,n;
	sieve();
	while(~scanf("%d",&n))
	{
		if(n%2)
		{
			m=n-2;
			if(check(ara[m>>5],m&31)==0&&m>2)
				printf("%d is the sum of 2 and %d.\n",n,m);
			else
				printf("%d is not the sum of two primes!\n",n);
			continue;
		}

		l=1;h=ll-1;
		nn=n/2;
		while(l<=h)
		{
			m=(l+h)/2;
			if(pr[m]>nn)
				h=m-1;
			else
				l=m+1;
		}
		fg=0;
		for(i=h;i>=1;i--)
		{
			m=n-pr[i];
			if(m<=1)
				break;
			if((m%2==0&&m!=2)||m==pr[i])
				continue;
			if(check(ara[m>>5],m&31)==0)
			{
				j=min(pr[i],m);
				k=max(m,pr[i]);
				fg=1;
				break;
			}
		}
		if(fg)
			printf("%d is the sum of %d and %d.\n",n,j,k);
		else
			printf("%d is not the sum of two primes!\n",n);
	}
	return 0;
}