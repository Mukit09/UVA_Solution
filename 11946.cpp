/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 3097 (11946 - Code Number) */
/* SUBMISSION: 09472523 */
/* SUBMISSION TIME: 2011-11-15 03:03:10 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

int main()
{
    long t,i,k,l;
    char ch[100],letter[15]="OIZEASGTBP";

    scanf("%ld\n",&t);
    while(t--)
    {
        while(gets(ch))
        {
            l=strlen(ch);
            if(!l)
			{
				break;
			}

            for(i=0;i<l;i++)
            {
                k=ch[i]-48;
                if(k>=0&&k<=9)
				{
                    ch[i]=letter[k];
				}
            }
            printf("%s\n",ch);
        }
        if(t==1)
		{
			printf("\n");
		}
    }
    return 0;
}
