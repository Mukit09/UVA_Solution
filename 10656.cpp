#include<stdio.h>

int main()
{
	long i,a[1005],n,j,k;
	while(scanf("%ld",&n)&&n)
	{
		j=1;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&k);
			if(k!=0)
			{
				a[j++]=k;
			}
		}
		if(j>1)
		{
			printf("%ld",a[1]);
			for(i=2;i<j;i++)
			{
				printf(" %ld",a[i]);
			}
		}
		else if(j==1)
			printf("0");
		printf("\n");
	}
	return 0;
}