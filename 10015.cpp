#include<stdio.h>
#include<math.h>
#define si 33000
long pr[si],a[si],len;

void sieve()
{
	long i,j,n=si-10,root;
	pr[len++]=2;
	root=sqrt(n);
	for(i=3;i<=n;i=i+2)
	{
		if(a[i]==0)
		{
			pr[len++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=n;j+=2*i)
					a[j]=1;
			}
		}
		a[i+1]=1;
    }
}

int main()
{
	sieve();
	long n,s,i;
	while(scanf("%ld",&n)&&n)
	{
		s=0;
		for(i=1;i<=n;i++)
			s=(s+pr[n-i])%i;     
		printf("%ld\n",s+1);
	}
	return 0;
}