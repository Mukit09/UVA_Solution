/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1311 (10370 - Above Average) */
/* SUBMISSION: 08881691 */
/* SUBMISSION TIME: 2011-05-24 17:17:27 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
	double a[1001],sum,av,x,k,n;
	long i,j,t;
	scanf("%ld",&t);
	while(t--)
	{
		k=0;
		sum=0;
		scanf("%lf",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			sum=sum+a[i];
		}
			av=sum/n;
		

			for(j=0;j<n;j++)
			{
				if(av<a[j])
					k++;
			}
				x=(k/n)*100;
			
		
		printf("%.3lf%%\n",x);
		
	}
	return 0;
}