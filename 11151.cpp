#include<stdio.h>
#include<string.h>
#define si 1010

char ch1[si],ch2[si];
long a[si][si];
long l1,i,j,t;

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch1);
		l1=strlen(ch1);
		for(i=0,j=l1-1;i<l1;i++,j--)
			ch2[i]=ch1[j];
		ch2[i]=0;
		for(i=0;i<=l1;i++)
		{
			for(j=0;j<=l1;j++)
			{
				if(i==0||j==0)
					a[i][j]=0;
				else if(ch1[i-1]==ch2[j-1])
					a[i][j]=a[i-1][j-1]+1;
				else
					a[i][j]=max(a[i][j-1],a[i-1][j]);
			}
		}
		printf("%ld\n",a[l1][l1]);
	}
	return 0;
}