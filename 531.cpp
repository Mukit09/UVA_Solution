#include<stdio.h>
#include<string.h>
#define si 110

char ch[si][40],ch1[si][40],ch2[si][40];
long x=0,i,j,a[si][si],m,n,l,k;

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

void write(long i,long j)
{
	if(i==0||j==0) return ;
	else if(strcmp(ch1[i],ch2[j])==0)
	{
		strcpy(ch[x++],ch1[i]);
		write(i-1,j-1);
	}
	else
	{
		if(a[i-1][j]>a[i][j-1])
			write(i-1,j);
		else write(i,j-1);
	}
}

int main()
{
	long i;
	while(scanf("%s",ch1[1])!=EOF)
	{
		m=2;
		while(scanf("%s",ch1[m])&&strcmp(ch1[m],"#")!=0)
		{
			m++;
		}
		m--;
		n=1;
		while(scanf("%s",ch2[n])&&strcmp(ch2[n],"#")!=0)
		{
			n++;
		}
		n--;
		for(i=0;i<=m;i++)
			a[i][0]=0;
		for(i=0;i<=n;i++)
			a[0][j]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(strcmp(ch1[i],ch2[j])==0)
					a[i][j]=a[i-1][j-1]+1;
				else 
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		x=0;
		write(m,n);
		if(a[m][n]!=0)
		{
			printf("%s",ch[x-1]);
			for(i=x-2;i>=0;i--)
				printf(" %s",ch[i]);
		}
		printf("\n");
	}
	return 0;
}