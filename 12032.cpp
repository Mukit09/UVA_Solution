#include<stdio.h>

long a[1000000];

int main()
{
	long t,n,i,k=1,max,d;

	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);

		max=0;
		for(i=n;i>=2;i--)
		{
			d=a[i]-a[i-1];
			if(d>max)
				max=d;
			else if(d==max)
				max++;
		}
		if(a[1]==max)
			max++;
		else if(a[1]>max)
			max=a[1];

		printf("Case %ld: %ld\n",k++,max);
	}
	return 0;
}
