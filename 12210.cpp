#include<stdio.h>

long i,mn,n,m,x=1,a;

int main()
{
	while(~scanf("%ld%ld",&n,&m)&&(n||m))
	{
		mn=100;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a);
			if(mn>a)
				mn=a;
		}
		for(i=1;i<=m;i++)
			scanf("%ld",&a);
		if(n<=m)
			printf("Case %ld: 0\n",x++);
		else
			printf("Case %ld: %ld %ld\n",x++,n-m,mn);
	}
	return 0;
}
