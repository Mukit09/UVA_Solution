#include<stdio.h>

int main()
{
	long k=1,t,n,a[10],i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		j=1;
		for(i=2;;i++)
		{
			if(n%i==0)
				a[j++]=i;
			if(j==3)
				break;
		}
		printf("Case #%ld: %ld = %ld * %ld = %ld * %ld\n",k++,n,a[1],n/a[1],a[2],n/a[2]);
	}
	return 0;
}