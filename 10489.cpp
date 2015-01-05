#include<stdio.h>

int main()
{
	long i,t,j,k,q,p,m,n,b;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&b);
		q=0;
		for(i=1;i<=b;i++)
		{
			p=1;
			scanf("%ld",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%ld",&m);
				p=((p%n)*(m%n))%n;
			}
			q=((q%n)+(p%n))%n;
		}
		printf("%ld\n",q);
	}
	return 0;
}