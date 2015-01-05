/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1730 (10789 - Prime Frequency) */
/* SUBMISSION: 09593447 */
/* SUBMISSION TIME: 2011-12-26 18:15:30 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<math.h>
#include<string.h>

long pr[2005];

void sieve()
{
	int i,j;

	pr[0]=1;
	pr[1]=1;
	for(i=2;i<=sqrt(2005);i++)
	{
		if(pr[i]==0)
		{
			for(j=2;i*j<=2003;j++)
			{
				pr[i*j]=1;
			}
		}   
	}
}

int prime(long n)
{
	if(pr[n]==0)
		return 1;
	else
		return 0;
}

long a[125];

int main()
{
	char ch[2005];
	long l,i,k,t,flag;
	sieve();
	scanf("%ld",&t);
	getchar();
	for(k=1;k<=t;k++)
	{
		for(i=48;i<=122;i++)
		{
			a[i]=0;
		}
		gets(ch);
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			if((ch[i]>47&&ch[i]<58)||(ch[i]>64&&ch[i]<91)||(ch[i]>96&&ch[i]<123))
			{
				a[ch[i]]++;
			}
		}
		flag=0;
		printf("Case %ld: ",k);
		for(i=48;i<=122;i++)
		{
			if(prime(a[i])==1)
			{
				printf("%c",i);
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("empty");
		}
		printf("\n");
	}
	return 0;
}