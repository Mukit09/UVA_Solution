/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1876 (10935 - Throwing cards away I) */
/* SUBMISSION: 09516591 */
/* SUBMISSION TIME: 2011-11-29 03:59:33 */
/* LANGUAGE: 1 */

#include<stdio.h>

int main()
{
	long p,k,i,j,a[100],n,b[100];
	while(scanf("%ld",&p)!=EOF)
	{
		if(p==0)
			break;
		if(p==1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
			continue;
		}
		n=p;
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		for(i=1,j=n+1,k=1;;i++,j++,k++)
		{
			b[k]=a[i];
			a[j]=a[i+1];
			i++;
			p=p-1;
			if(p==1)
				break;
		}
		printf("Discarded cards: ");
		for(i=1;i<k;i++)
		{
			printf("%ld, ",b[i]);
		}
		printf("%ld\n",b[i]);
		printf("Remaining card: %ld\n",a[j-1]);
	}
	return 0;
}