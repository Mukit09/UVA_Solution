#include<stdio.h>
#define inf 2147483647

int main()
{
	long t,i,j,k,n,ar,min;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		min=inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i*j>n)
					break;
				for(k=1;k<=n;k++)
				{
					if(i*j*k>n)
						break;
					if(i*j*k==n)
					{
						ar=2*(i*j+j*k+k*i);
						if(min>ar)
							min=ar;
					}
				}
			}
		}
		if(n==0)
			min=0;
		printf("%ld\n",min);
	}
	return 0;
}