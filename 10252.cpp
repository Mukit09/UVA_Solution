/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1193 (10252 - Common Permutation) */
/* SUBMISSION: 09586762 */
/* SUBMISSION TIME: 2011-12-23 15:48:00 */
/* LANGUAGE: 1 */

#include <stdio.h>

int c1[26];
int c2[26];

char ch1[1005];
char ch2[1005];

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
    int i,j;
    while(~scanf("%s",ch1))
    {
        scanf("%s",ch2);
        for(i=0;i<26;i++)
		{
			c1[i]=c2[i]=0;
		}
        for(i=0;ch1[i]!='\0';i++)
		{
            c1[ch1[i]-'a']++;
		}
        for(i=0;ch2[i]!='\0';i++)
		{
            c2[ch2[i]-'a']++;
		}
        for(i=0;i<26;i++)
        {
            j = min(c1[i],c2[i]);
            while(j-->0)
			{
                printf("%c",i+'a');
			}
        }
        printf("\n");
    }
    return 0;

}
