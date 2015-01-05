/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2655 (11608 - No Problem) */
/* SUBMISSION: 08992903 */
/* SUBMISSION TIME: 2011-06-27 09:46:07 */
/* LANGUAGE: 3 */

#include<stdio.h>
int main()
{
	long a[20],b[20],i=1,j,k,n,m;
	while(1)
	{
		scanf("%ld",&n);
		if(n<0)
			break;

		for(j=1;j<=12;j++)
		{
			scanf("%ld",&a[j]);
		}
		for(k=1;k<=12;k++)
		{
			scanf("%ld",&b[k]);
		}
		printf("Case %ld:\n",i++);
		for(m=1;m<=12;m++)
		{
			if(m==1)
			{
				if(n>=b[m])    
				{
					printf("No problem! :D\n");
					n=n-b[m]+a[m];
				}
				else
				{
					printf("No problem. :(\n");                        
     				n=n+a[m];                                     
				}  
			}
			if(m>1&&m<=12)
			{
				if(n>=b[m])    
				{
					printf("No problem! :D\n");
					n=n-b[m]+a[m];
				}
				else
				{
					printf("No problem. :(\n");                        
     				n=n+a[m];                                     
				}
			}
		}    
	}
	return 0;
}