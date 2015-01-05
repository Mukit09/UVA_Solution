/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2828 (11728 - Alternate Task) */
/* SUBMISSION: 09550131 */
/* SUBMISSION TIME: 2011-12-11 01:53:22 */
/* LANGUAGE: 1 */

#include <stdio.h>

int main()
{
    int n,sum,i,j,t=1,flag=0;

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(j=n,flag=0;j>=1;j--)
        {
            for(i=1,sum=0;i<=j/2;i++)
            {
                if(j%i==0)
                {
                    sum+=i;
                }
            }
            sum+=j;

            if(sum==n)
            {
                printf("Case %d: %d\n",t,j);
                flag=1;
                break;
            }
        }
        if(flag==0)
              printf("Case %d: -1\n",t);
        t++;
    }
	return 0;
}