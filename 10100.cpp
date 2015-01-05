#include<stdio.h>
#include<string.h>
#define si 1050

char ch1[si][30],ch2[si][30];
char st1[si],st2[si],st[30];

long i,j,k=1,l1,l2,n,m,a,fg;
long ar[si][si];

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}

int main()
{
	while(gets(st1))
	{
		fg=0;
		l1=strlen(st1);
		gets(st2);
		l2=strlen(st2);
		if(l1==0||l2==0)
			fg=1;
		if(fg)
		{
			printf("%2ld. Blank!\n",k++);
			continue;
		}
		i=0;j=0;
		while(i<l1)
		{
			if((st1[i]>=65&&st1[i]<=90)||(st1[i]>=97&&st1[i]<=122)||st1[i]>=48&&st1[i]<=57)
			{
				st[a++]=st1[i];
				if(st1[i+1]<48||(st1[i+1]>57&&st1[i+1]<65)||st1[i+1]>122||(st1[i+1]>90&&st1[i+1]<97))
				{
					st[a]=0;
					strcpy(ch1[j++],st);
					a=0;
				}
			}
			i++;
		}
		m=j;
		j=a=i=0;
		while(i<l2)
		{
			if((st2[i]>=65&&st2[i]<=90)||(st2[i]>=97&&st2[i]<=122)||(st2[i]>=48&&st2[i]<=57))
			{
				st[a++]=st2[i];
				if(st2[i+1]<48||(st2[i+1]>57&&st2[i+1]<65)||st2[i+1]>122||(st2[i+1]>90&&st2[i+1]<97))
				{
					st[a]=0;
					strcpy(ch2[j++],st);
					a=0;
				}
			}
			i++;
		}
		n=j;
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					ar[i][j]=0;
				else if(strcmp(ch1[i-1],ch2[j-1])==0)
					ar[i][j]=ar[i-1][j-1]+1;
				else
					ar[i][j]=max(ar[i][j-1],ar[i-1][j]);
			}
		}
		printf("%2ld. Length of longest match: %ld\n",k++,ar[m][n]);
	}
	return 0;
}