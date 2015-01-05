#include<stdio.h>

long a[120],i,j,flg,t,n,k=1,m;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		flg=0;
		for(i=0;i<101;i++)
			a[i]=0;
		scanf("%ld",&n);
		for(j=0;j<n;j++)
		{
			for(i=0;i<n;i++)
			{
				scanf("%ld",&m);
				a[m]++;
				if(a[m]>n)
					flg=1;
			}
		}
		if(flg)
			printf("Case %ld: no\n",k++);
		else
			printf("Case %ld: yes\n",k++);
	}
	return 0;
}