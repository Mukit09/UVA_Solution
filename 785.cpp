#include<stdio.h>
#include<string.h>

char ch[50][100],s;

long row,fg;

void dfs1(long r,long c)
{
	long l;

	l=strlen(ch[r]);
	if((r>=row-1||r<0||c>=l||c<0||ch[r][c]=='X'||ch[r][c]==s)&&fg)
		return ;

	if(!fg)
		fg=1;

	ch[r][c]=s;

	dfs1(r+1,c);
	dfs1(r-1,c);
	dfs1(r,c+1);
	dfs1(r,c-1);
}

int main()
{
	char st[90];
	long i=0,j;
	while(gets(st))
	{	
		if(st[0]=='_')
		{
			strcpy(ch[i++],st);
			row=i;
			for(i=0;i<row-1;i++)
			{
				for(j=0;ch[i][j];j++)
				{
					if(ch[i][j]!='X'&&ch[i][j]!=' ')
					{
						fg=0;
						s=ch[i][j];
						dfs1(i,j);
					}
				}
			}
			for(i=0;i<row;i++)
				puts(ch[i]);
			i=0;
		}
		else
			strcpy(ch[i++],st);
	}
	return 0;
}