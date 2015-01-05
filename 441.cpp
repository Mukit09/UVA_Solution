#include<stdio.h>

int main()
{
	long i,j,k,l,m,n,o,a[15],fg=0;
	while(~scanf("%ld",&o)&&o)
	{
		if(fg)
			printf("\n");
		fg=1;
		for(i=1;i<=o;i++)
			scanf("%ld",&a[i]);

		for(i=1;i<=o-5;i++)
		{
			for(j=i+1;j<=o-4;j++)
			{
				for(k=j+1;k<=o-3;k++)
				{
					for(l=k+1;l<=o-2;l++)
					{
						for(m=l+1;m<=o-1;m++)
						{
							for(n=m+1;n<=o;n++)
							{
								printf("%ld %ld %ld %ld %ld %ld\n",a[i],a[j],a[k],a[l],a[m],a[n]);
							}
						}
					}
				}
			}
		}

	}
	return 0;
}
