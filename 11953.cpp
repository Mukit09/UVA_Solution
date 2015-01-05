/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 3104 (11953 - Battleships) */
/* SUBMISSION: 09653493 */
/* SUBMISSION TIME: 2012-01-17 13:07:15 */
/* LANGUAGE: 1 */

#include<stdio.h>

int main()

{
	long n,i,j,k,t,c,a;
	char ch[101][101];
	scanf("%ld",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%ld",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
		}
		c=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]=='x')
				{
					c++;
					if(ch[i][j+1]=='x'||ch[i][j+1]=='@')
					{
						while(ch[i][j]=='x'||ch[i][j]=='@')
						{
							ch[i][j]='.';
							j++;
						}
					}
					else if(ch[i+1][j]=='x'||ch[i+1][j]=='@')
					{
						a=i;
						while(ch[a][j]=='x'||ch[a][j]=='@')
						{
							ch[a][j]='.';
							a++;
						}
					}
				}
			}
		}
		printf("Case %ld: %ld\n",k,c);
	}
	return 0;
}