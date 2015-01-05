/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2456 (11461 - Square Numbers) */
/* SUBMISSION: 08773428 */
/* SUBMISSION TIME: 2011-04-23 16:43:23 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<math.h>
main()
{
	long a,b,i,k;
		while(scanf("%ld%ld",&a,&b)!=EOF)
		{
			if(a==0&&b==0)
			break;
			k=0;
			for(i=1;i<=b;i++)
			{
			   if((i*i)>=a&&(i*i)<=b)
				 k++; 
			}
		printf("%ld\n",k);	   
				
		}
   return 0;
}