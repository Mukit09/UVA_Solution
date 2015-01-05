/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1003 (10062 - Tell me the frequencies!) */
/* SUBMISSION: 09597165 */
/* SUBMISSION TIME: 2011-12-28 04:07:03 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

long a[150];

int main()
{
	long i,j,max,l,flag=0;
	char ch[1005];
	while(gets(ch))
	{
		for(i=32;i<=127;i++)
		{
			a[i]=0;
		}
		l=strlen(ch);
		max=0;
		for(i=0;i<l;i++)
		{
			a[ch[i]]++;
			if(a[ch[i]]>max)
			{
				max=a[ch[i]];
			}
		}
		j=1;
		if(flag==1)
			printf("\n");
		flag=1;
		while(j!=(max+1))
		{
			i=127;
			while(i!=31)
			{
				if(a[i]==j)
				{
					printf("%ld %ld\n",i,a[i]);
				}
				i--;
			}
			j++;
		}
		
	}
	return 0;
}
