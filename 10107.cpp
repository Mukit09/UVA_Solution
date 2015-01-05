#include<stdio.h>

long a[10010];

int main()
{
	long i,k=1,n,re;
	a[0]=-999999;
	while(scanf("%ld",&n)==1)
	{
		for(i=k++;n<a[i-1];i--)
		{
			a[i]=a[i-1];
		}
		a[i]=n;
		if(k%2==0)
		{
			re=a[k/2];
		}
		else
		{
			re=(a[k/2]+a[k/2+1])/2;
		}
		printf("%ld\n",re);
	}
	return 0;
}