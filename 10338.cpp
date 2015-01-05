/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1279 (10338 - Mischievous Children) */
/* SUBMISSION: 09590918 */
/* SUBMISSION TIME: 2011-12-25 12:05:26 */
/* LANGUAGE: 1 */

#include <stdio.h>
#include <string.h>

long ascii[26];
long factorials[21];

long double results[21];

int main()
{
    long double res;
    long i,j,t;
    long k;
    char s[21];
    results[1]=1;
    for(i=2;i<21;i++)
	{
		results[i]=results[i-1]*i;
	}
    scanf("%ld",&t);
    getchar();
    for(k=1;k<=t;k++)
    {
        res = 1;
        gets(s);
		for(j=0;j<=20;j++)factorials[j]=0;

        for(i=0;i<26;i++)ascii[i]=0;
        i = strlen(s);
        for(j=0;j<i;j++)
		{
            ascii[s[j]-'A']++;
		}
        for(j=0;j<26;j++)
		{
            factorials[ascii[j]]++;
		}
        res = results[i];
        for(j=2;j<=20;j++)
		{
            for(i=1;i<=factorials[j];i++)
			{
                res/=results[j];
			}
		}
        printf("Data set %ld: %.0llf\n",k,res);
    }
    return 0;
}