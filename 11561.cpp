#include<stdio.h>

long a[60][60],cnt,i,j,n,m,x,y;
char ch[60][60];

void dfs(long r,long c)
{
	if(ch[r][c]=='#')
		return ;
	
	if(ch[r][c]=='G'&&a[r][c]==1)
	{
		ch[r][c]='#';
		cnt++;
		return ;
	}
	else if(ch[r][c]!='G'&&a[r][c]==1)
	{
		ch[r][c]='#';
		return ;
	}
	if(ch[r][c]=='G')
		cnt++;
	ch[r][c]='#';
	dfs(r,c+1);
	dfs(r,c-1);
	dfs(r+1,c);
	dfs(r-1,c);
}	        

int main()
{
	while(~scanf("%ld%ld",&m,&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;j<m;j++)
			{
				if(ch[i][j]=='P')
					x=i,y=j;
				a[i][j]=0;
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ch[i][j]=='T')
				{
					if(i-1>=0)
						a[i-1][j]=1;
					if(i+1<n)
						a[i+1][j]=1;
					if(j-1>=0)
						a[i][j-1]=1;
					if(j+1<m)
						a[i][j+1]=1;
				}
			}
		}
		cnt=0;
		dfs(x,y);
		printf("%ld\n",cnt);
	}
	return 0;
}