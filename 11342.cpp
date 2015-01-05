#include<stdio.h>

int main()
{
	long i,j,k,n,t,fg;
	scanf("%ld",&t);
	while(t--)
	{
		fg=0;
		scanf("%ld",&n);
		if(n%8==7)                      //if any integer n%8==7 then n can't be expressed by three square(law)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i*i<=n;i++)
		{
			for(j=i;i*i+j*j<=n;j++)
			{
				for(k=j;i*i+j*j+k*k<=n;k++)
				{
					if(n==i*i+j*j+k*k)
					{
						fg=1;
						break;
					}
				}
				if(fg)
					break;
			}
			if(fg)
				break;
		}
		if(fg)
			printf("%ld %ld %ld\n",i,j,k);
		else
			printf("-1\n");
	}
	return 0;
}
