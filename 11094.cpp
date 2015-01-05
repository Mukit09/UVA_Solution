#include<stdio.h>

char st[30][30],ch;
long n,m,cnt,i,j,x,y;

void dfs(long r,long c)
{
	if(c<0||c==n||r<0||r==m||st[r][c]!=ch)
		return ;
	
	if(st[r][c]==ch)
	{	
		st[r][c]='*';
		cnt++;
		if(c==0&&st[r][n-1]==ch)
			dfs(r,n-1);
		else if(c==n-1&&st[r][0]==ch)
			dfs(r,0);
	}
	dfs(r,c+1);
	dfs(r,c-1);
	dfs(r+1,c);
	dfs(r-1,c);
}


int main()
{
	long mx;
	while(~scanf("%ld%ld",&m,&n))
	{
		for(i=0;i<m;i++)
			scanf("%s",st[i]);
		scanf("%ld%ld",&x,&y);
		ch=st[x][y];
		mx=cnt=0;
		dfs(x,y);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(st[i][j]==ch)
				{
					cnt=0;
					dfs(i,j);
					if(mx<cnt)
						mx=cnt;
				}
			}
		}
		printf("%ld\n",mx);
	}
	return 0;
}