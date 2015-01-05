#include<stdio.h>
#define inf -2147483646

int main()
{
	long t,i,mx,a,mx_dif,dif,n;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld",&mx);
		mx_dif=inf;
		for(i=2;i<=n;i++)
		{
			scanf("%ld",&a);
			dif=mx-a;
			if(dif>mx_dif)
				mx_dif=dif;
			if(a>mx)
				mx=a;
		}
		printf("%ld\n",mx_dif);
	}
	return 0;
}
