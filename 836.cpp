#include<stdio.h>
#include<string.h>

char ch[30][30];
long a[30][30],i,j,k,n,mx,mx_sm,dp[30],t;

int main()
{
	scanf("%ld",&t);
	while(getchar()!='\n');
	while(getchar()!='\n');
	while(t--)
	{
		i=0;
		while(gets(ch[i]))
		{
			if(strcmp(ch[i],"")==0)
				break;
			k=strlen(ch[i]);
			for(j=0;j<k;j++)
				a[i][j]=ch[i][j]-48;
			i++;
		}
		n=i;
		mx=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				dp[j]=0;
			for(j=i;j<n;j++)
			{
				mx_sm=0;
				for(k=0;k<n;k++)
				{
					dp[k]+=a[j][k];
					if(dp[k]==j-i+1)
						mx_sm+=dp[k];
					else
						mx_sm=0;
					if(mx<mx_sm)
						mx=mx_sm;
				}
			}
		}
		printf("%ld\n",mx);
		if(t)
			puts("");
	}
	return 0;
}