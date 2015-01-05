#include<stdio.h>
#define si 15

char ch[si][si];
long n,v,t,i,j,k,test=1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%s",ch[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]=='.')
				{
					for(k=65;k<=90;k++)
					{
						if(ch[i-1][j]!=k&&ch[i+1][j]!=k&&ch[i][j+1]!=k&&ch[i][j-1]!=k)
						{
							ch[i][j]=k;
							break;
						}
					}
				}
			}
		}
		printf("Case %ld:\n",test++);
		for(i=0;i<n;i++)
			puts(ch[i]);
	}
	return 0;
}