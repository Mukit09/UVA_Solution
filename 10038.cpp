/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 979 (10038 - Jolly Jumpers) */
/* SUBMISSION: 09479628 */
/* SUBMISSION TIME: 2011-11-17 07:53:26 */
/* LANGUAGE: 1 */

#include<stdio.h>

long a[3005],d[3005];
int main()
{
	long k,n,i,flag,e,d1;
	while(scanf("%ld",&n)!=EOF)
	{
		i=0;
		flag=0;
		for(k=1;k<=n;k++)
		{
			scanf("%ld",&a[k]);
		}
		for(k=1;k<n;k++)
		{
			if(a[k]>a[k+1])
			{
				d[k]=a[k]-a[k+1];
			}
			else
			{
				d[k]=a[k+1]-a[k];
			}
			if(d[k]<0)
			{
				d[k]=(-1)*d[k];		
			}
			if(d[k]>=n)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(i=n-1;i>=1;i--)
			{
				for(k=1;k<=i-1;k++)
				{
					if(d[k]>d[k+1])
					{
						e=d[k];
						d[k]=d[k+1];
						d[k+1]=e;
					}
				}
			}
			for(i=1;i<n-1;i++)
			{
				d1=d[i+1]-d[i];
				if(d1>1||d1==0)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}