#include<stdio.h>
#include<algorithm>
using namespace std;

long i,n,sum,cost,a[10];

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		sort(a,a+n);
		cost=0;
		while(n>1)
		{
			cost+=a[0]+a[1];
			sum=a[0]+a[1];
			for(i=2;i<n;i++)
				a[i-2]=a[i];
			i=n-3;
			while(a[i]>sum)
			{
				a[i+1]=a[i];
				i--;
			}
			a[i+1]=sum;
			n--;
		}
		printf("%ld\n",cost);
	}
	return 0;
}