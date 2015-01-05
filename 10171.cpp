#include<stdio.h>
#define inf 214748364
#define si 110

long m[si][si],b[si][si],i,j,k,cost,n,fg,mn,ans[si],sm;
char age[10],dir[10],n1[10],n2[10];

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		for(i=65;i<=90;i++)
		{
			for(j=65;j<=90;j++)
			{
				if(i==j)
					m[i][j]=b[i][j]=0;
				else
					m[i][j]=b[i][j]=inf;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s%s%s%s%ld",age,dir,n1,n2,&cost);
			if(age[0]=='M')
			{
				if(dir[0]=='U')
				{
					if(m[n1[0]][n2[0]]>cost)
						m[n1[0]][n2[0]]=cost;
				}
				else
				{
					if(m[n1[0]][n2[0]]>cost)
						m[n1[0]][n2[0]]=m[n2[0]][n1[0]]=cost;
				}
			}
			else
			{
				if(dir[0]=='U')
				{
					if(b[n1[0]][n2[0]]>cost)
						b[n1[0]][n2[0]]=cost;
				}
				else
				{
					if(b[n1[0]][n2[0]]>cost)
						b[n1[0]][n2[0]]=b[n2[0]][n1[0]]=cost;
				}
			}
		}
		for(k=65;k<=90;k++)
		{
			for(i=65;i<=90;i++)
			{
				for(j=65;j<=90;j++)
				{
					if(b[i][j]>b[i][k]+b[k][j])
						b[i][j]=b[i][k]+b[k][j];
					if(m[i][j]>m[i][k]+m[k][j])
						m[i][j]=m[i][k]+m[k][j];
				}
			}
		}
		scanf("%s%s",n1,n2);
		fg=0;
		mn=inf;
		for(i=65;i<=90;i++)

		{
			sm=b[n1[0]][i];
			sm+=m[n2[0]][i];
			if(sm<inf&&sm<mn)
			{
				j=0;
				fg=1;
				mn=sm;
				ans[j]=i;
				j++;
			}
			else if(sm<inf&&sm==mn)
				ans[j++]=i;
		}
		if(fg)
		{
			printf("%ld",mn);
			for(i=0;i<j;i++)
				printf(" %c",ans[i]);
			printf("\n");
		}
		else
			printf("You will never meet.\n");
	}
	return 0;
}