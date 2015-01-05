#include<stdio.h>
#include<string.h>

long a[1010][1010];

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	char ch1[1010],ch2[1010];
	long m,n,i,j;
	while(gets(ch1))
	{
		m=strlen(ch1);
		gets(ch2);
		n=strlen(ch2);
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					a[i][j]=0;
				else if(ch1[i-1]==ch2[j-1])
					a[i][j]=a[i-1][j-1]+1;
				else
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		printf("%ld\n",a[m][n]);
	}
	return 0;
}