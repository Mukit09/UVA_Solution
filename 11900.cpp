#include<stdio.h>

int main()
{
	long t,k=1,i,n,p,q,a[50],sum;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&n,&p,&q);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		sum=0;
		for(i=1;i<=n;i++)
		{
			if(i>p||sum+a[i]>q)
				break;

			sum+=a[i];
		}
		printf("Case %ld: %ld\n",k++,i-1);
	}
	return 0;
}