#include<stdio.h>
#include<string.h>

char ch[40][90];

long row;

void dfs(long r,long c)
{
	long l;
	l=strlen(ch[r]);
	if(r>=row-1||r<0||c>=l||c<0||ch[r][c]=='X'||ch[r][c]=='#')
		return ;
	ch[r][c]='#';

	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main()
{
	long t,i,j;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		i=0;
		while(1)
		{
			gets(ch[i++]);
			if(ch[i-1][0]=='_')
				break;
		}
		row=i;
		for(i=0;i<row;i++)
		{
			for(j=0;ch[i][j];j++)
			{
				if(ch[i][j]=='*')
					dfs(i,j);
			}
		}
		for(i=0;i<row;i++)
			puts(ch[i]);
	}
	return 0;
}