/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 2345 (11360 - Have Fun with Matrices) */
/* SUBMISSION: 09614640 */
/* SUBMISSION TIME: 2012-01-03 13:57:39 */
/* LANGUAGE: 1 */

#include<stdio.h>
#include<string.h>

char ch[15][15];
char ch1[15];
char s[15];

int main()
{
	long T,t=1,n,i,m,j,k,a,b;
	scanf("%ld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%ld",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			gets(ch[i]);
		}
		scanf("%ld",&m);
		getchar();

		for(k=1;k<=m;k++)
		{
			gets(ch1);
			if(ch1[0]=='t')
			{
				for(i=0;i<n;i++)
				{
					for(j=i;j<n;j++)
					{
						s[j]=ch[i][j];
					}
					for(j=i;j<n;j++)
					{
						ch[i][j]=ch[j][i];
					}
					for(j=i;j<n;j++)
					{
						ch[j][i]=s[j];
					}
				}
			}
			else if(ch1[0]=='r')
			{
				a=ch1[4]-48;
				b=ch1[6]-48;
				for(i=0;i<n;i++)
				{
					s[i]=ch[a-1][i];
				}
				for(i=0;i<n;i++)
				{
					ch[a-1][i]=ch[b-1][i];
				}
				for(i=0;i<n;i++)
				{
					ch[b-1][i]=s[i];
				}
			}
			else if(ch1[0]=='c')
			{
				a=ch1[4]-48;
				b=ch1[6]-48;
				for(i=0;i<n;i++)
				{
					s[i]=ch[i][a-1];
				}
				for(i=0;i<n;i++)
				{
					ch[i][a-1]=ch[i][b-1];
				}
				for(i=0;i<n;i++)
				{
					ch[i][b-1]=s[i];
				}
			}
			else if(ch1[0]=='i')
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if(ch[i][j]>=48&&ch[i][j]<=56)
						{
							ch[i][j]=ch[i][j]+1;
						}
						else
						{
							ch[i][j]=48;
						}
					}
				}
			/*	for(i=0;i<n;i++)
				{
					puts(ch[i]);
				}*/
			}
			else if(ch1[0]=='d')
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						if(ch[i][j]>=49&&ch[i][j]<=57)
						{
							ch[i][j]=ch[i][j]-1;
						}
						else
						{
							ch[i][j]=57;
						}
					}
				}
			}
		}
		printf("Case #%ld\n",t);
		for(i=0;i<n;i++)
		{
			puts(ch[i]);
		}
		printf("\n");
	}
	return 0;
}