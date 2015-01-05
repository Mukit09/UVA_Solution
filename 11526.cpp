/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2521 (11526 - H(n)) */
/* SUBMISSION: 09557246 */
/* SUBMISSION TIME: 2011-12-13 15:07:04 */
/* LANGUAGE: 1 */


#include<stdio.h>
#include<math.h>

long long H(long n)
{
	long long lq,sum,pq,i,l;
	l=sqrt(n);
	sum=0;
	for(i=1;i<=l;i++) 
	{
        lq=n/i;
		pq=n/(i+1);
		if(pq>=l)
			sum=sum+(lq-pq)*i+lq;
		else
			sum+=lq;
	}
    return sum;
}

int main()
{
	long i,t,n;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&n);
		if(n<=0)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n",H(n));
	}
	return 0;
}

