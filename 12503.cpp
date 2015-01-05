#include<stdio.h>
#include<string.h>

long x,i,j,m,n,t,l,a[110][20];
char ch[110][20];

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		getchar();
		x=0;
		for(i=0;i<n;i++)
		{
			a[i][0]=0;
			gets(ch[i]);
			if(ch[i][0]=='L')
				a[i][0]=-1;
			else if(ch[i][0]=='R')
				a[i][0]=1;
		
			else
			{
				l=strlen(ch[i]);
				m=0;
				for(j=0;j<l;j++)
				{
					if(ch[i][j]>=48&&ch[i][j]<=57)
					{
						while(ch[i][j]>=48&&ch[i][j]<=57&&j<l)
						{
							m=m*10+ch[i][j]-48;
							j++;
						}
					}
				}
				m--;
				if(ch[m][0]=='R')
					a[i][0]=1;
				else if(ch[m][0]=='L')
					a[i][0]=-1;
				else
					a[i][0]=a[m][0];
			}
			x+=a[i][0];
		}
		printf("%ld\n",x);
	}
	return 0;
}