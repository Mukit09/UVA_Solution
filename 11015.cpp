#include<stdio.h>

int main()
{
	char ch[25][15];
	long n,m,i,j,k,c,a,b,q[25][25],t=1,min,sum;
	while(scanf("%ld%ld",&n,&m)&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch[i]);
			for(j=1;j<=n;j++)
			{
				if(i==j)
					q[i][j]=0;
				else
					q[i][j]=99999999;
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			q[a][b]=q[b][a]=c;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(q[i][j]>q[i][k]+q[k][j])
					{
						q[i][j]=q[i][k]+q[k][j];
					}
				}
			}
		}
		sum=0;
		min=9999999;
		for(i=1;i<=n;i++)
		{
			sum=0;
			for(j=1;j<=n;j++)
			{
				sum+=q[i][j];
			}
			if(sum<min)
			{
				k=i;
				min=sum;
			}
		}
		printf("Case #%ld : %s\n",t++,ch[k]);
	}
	return 0;
}