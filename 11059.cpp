#include<stdio.h>

int main()
{
	long k=1,n,a[25],max,pro,i,pro_rev,max_rev,j;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		pro=pro_rev=1;
		max=max_rev=0;
		for(i=0,j=n-1;i<n;i++,j--)
		{
			pro*=a[i];
			pro_rev*=a[j];
			if(max<pro)
			{
				max=pro;
			}
			if(max_rev<pro_rev)
			{
				max_rev=pro_rev;
			}
			if(pro==0)
			{
				pro=1;
			}
			if(pro_rev==0)
			{
				pro_rev=1;
			}
		}
		if(max_rev>max)
			max=max_rev;
		printf("Case #%ld: The maximum product is %ld.\n\n",k++,max);
	}
	return 0;
}