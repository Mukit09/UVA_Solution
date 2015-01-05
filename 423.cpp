#include<stdio.h>
#include<string.h>

int main()
{
	char ch[1010];
	long n,i,j,k,l,v,max;
	long a[110][110];
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					a[i][j]=0;
				else
					a[i][j]=999999999;
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<i+1;j++)
			{
				scanf("%s",ch);
				if(ch[0]>=48)
				{
					v=0;
					l=strlen(ch);
					for(k=0;k<l;k++)
						v=v*10+(ch[k]-48);
					a[i+1][j]=v;
					a[j][i+1]=v;
				}
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
		max=0;
		for(i=2;i<=n;i++)
		{
			if(a[1][i]>max)
				max=a[1][i];
		}
		printf("%ld\n",max);
	}
	return 0;
}
