/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2319 (11344 - The Huge One) */
/* SUBMISSION: 09613725 */
/* SUBMISSION TIME: 2012-01-03 07:52:20 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

int main()
{
	long a[15],l,i,j,k,n,t,c,flag;
	char ch[1005];
	scanf("%ld",&t);
	getchar();
	for(k=1;k<=t;k++)
	{
		flag=c=0;
		gets(ch);
		scanf("%ld",&n);
		getchar();
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&a[j]);
			getchar();
		}
		l=strlen(ch);
		for(j=1;j<=n;j++)
		{
			for(i=0;i<l;i++)
			{
				c=(c*10+(ch[i]-48))%a[j];
			}
			if(c!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("%s - Wonderful.\n",ch);
		else
			printf("%s - Simple.\n",ch);
	}
	return 0;
}