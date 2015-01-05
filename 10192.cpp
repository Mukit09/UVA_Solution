#include<stdio.h>
#include<string.h>

char ch1[105],ch2[105];

long a[105][105];
long m,n,i,j,k=1;

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

int main()
{
	while(gets(ch1))
	{
		if(strcmp(ch1,"#")==0)
			break;
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
		printf("Case #%ld: you can visit at most %ld cities.\n",k++,a[m][n]);
	}
	return 0;
}