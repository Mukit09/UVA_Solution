#include<stdio.h>
#define inf 99999999

long n,a[110][110],mx,s,cnt,cnt1;

void input()
{
	long i,j=1,k,sum,u,v;
	char ch;
	for(i=1;i<n;i++)
	{
		sum=k=0;
		while(ch=getchar())
		{
			if(ch>=48&&ch<=57)
			{
				sum=sum*10+(ch-48);
			}
			else if(ch==32||ch=='\n')
			{
				k++;
				if(k==1)
					u=sum;
				else if(k==2)
				{
					v=sum;
					k=0;
					a[u][v]=j;
				}
				sum=0;
				if(ch=='\n')
					break;
			}
		}
		j++;
	}
	mx=j;
}

void dfs(long r,long c)
{
	if(r<1||c<1||r>n||c>n)
		return ;
	if(a[r][c]>mx||a[r][c]!=s)
		return ;
	else
	{
		cnt1++;
		a[r][c]=inf;
	}
	dfs(r,c+1);
	dfs(r,c-1);
	dfs(r+1,c);
	dfs(r-1,c);
}

int main()
{
	long i,j;
	while(~scanf("%ld",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				a[i][j]=0;
		}
		getchar();
		input();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==0)
					a[i][j]=mx;
			}
		}
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]<=mx)
				{
					cnt1=0;
					s=a[i][j];
					dfs(i,j);
					if(cnt1==n)
						cnt++;
				}
			}
		}
		if(cnt==n)
			printf("good\n");
		else
			printf("wrong\n");
	}
	return 0;
}