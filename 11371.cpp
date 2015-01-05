/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2366 (11371 - Number Theory for Newbies) */
/* SUBMISSION: 09458525 */
/* SUBMISSION TIME: 2011-11-10 13:44:48 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

int main()
{
	char ch[1000],c,ch1[1000];
	long long i,mul,sum1,sum,sub,max,min,l,j;
	while(gets(ch))
	{
		sum1=0;
		sum=0;
		l=strlen(ch);
		for(i=l-1;i>=0;i--)
		{
			for(j=0;j<=i-1;j++)
			{
				if(ch[j]>ch[j+1])
				{
					c=ch[j];
					ch[j]=ch[j+1];
					ch[j+1]=c;
				}
			}
		}
		for(i=l-1,j=0;i>=0;i--,j++)
		{
			ch1[j]=ch[i];
			sum1=sum1*10+(ch1[j]-48);
		}
		if(ch[0]==48)
		{
			i=0;
			while(ch[i]==48)
			{
				i++;
			}
			c=ch[i];
			ch[0]=c;
			ch[i]=48;
		}
		for(i=0;i<l;i++)
		{
			sum=sum*10+ch[i]-48;
		}
		if(sum1>sum)
		{
			max=sum1;
			min=sum;
		}
		else
		{
			max=sum;
			min=sum1;
		}
		sub=max-min;
		mul=sub/9;
		printf("%lld - %lld = %lld = 9 * %lld\n",max,min,sub,mul);
	}
	return 0;
}