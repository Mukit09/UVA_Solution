#include<stdio.h>

char ch[105][105];

long m,n;

void dfs(long r,long c)
{
	if(r<0||c<0||r>=m||c>=n||ch[r][c]=='*')
		return ;

	ch[r][c]='*';

	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
	dfs(r+1,c+1);
	dfs(r-1,c-1);
	dfs(r+1,c-1);
	dfs(r-1,c+1);
}

int main()
{
	long i,j,count;
	while(scanf("%ld%ld",&m,&n)&&(m||n))
	{
		count=0;
		for(i=0;i<m;i++)
			scanf("%s",ch[i]);

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][j]=='@')
				{
					count++;
					dfs(i,j);
				}
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}