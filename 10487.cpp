#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	long a[1010],n,i,j,m,q,min,x=1,re,k;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);

		sort(a,a+n);
		printf("Case %ld:\n",x++);
		scanf("%ld",&m);
		while(m--)
		{
			min=99999999;
			scanf("%ld",&q);
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					k=abs(q-(a[i]+a[j]));
					if(k<min)
					{
						re=a[i]+a[j];
						min=k;
					}
				}
			}
			printf("Closest sum to %ld is %ld.\n",q,re);
		}
	}
	return 0;
}