#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	long a[30000],i,t,sum,n;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		sort(a,a+n);
	
		sum=0;
		for(i=n-3;i>=0;i-=3)
		{
			sum+=a[i];
		}
		printf("%ld\n",sum);
	}
	return 0;
}