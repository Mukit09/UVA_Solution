#include<stdio.h>
#include<string.h>

int main()
{
	long i,j,k,c,t,n,m,a[110],min;
	char ch[110][55],re[55],s;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%s",ch[i]);
			c=0;
			strcpy(re,ch[i]);
			for(j=n-1;j>=0;j--)
			{
				for(k=0;k<=j-1;k++)
				{
					if(re[k]>re[k+1])
					{
						s=re[k];
						re[k]=re[k+1];
						re[k+1]=s;
						c++;
					}
				}
			}
			a[i]=c;
		}
		for(i=1;i<=m;i++)
		{
			min=999999;
			for(j=1;j<=m;j++)
			{
				if(a[j]<min&&a[j]>=0)
					min=a[j];
			}
			for(j=1;j<=m;j++)
			{
				if(min==a[j])
				{
					puts(ch[j]);
					a[j]=-1;
				}
			}
		}
		if(t)
			printf("\n");
	}
	return 0;
}

