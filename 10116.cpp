#include<stdio.h>

char ch[15][15];
long a[15][15],cnt,fg,i,j,n,m,s,v,visit[15][15];

void dfs(long r,long c)
{
	if(r<0||c<0||r==n||c==m)
		return ;

	if(visit[r][c])
	{
		fg=1;
		v=a[r][c];
		return ;
	}
		
	visit[r][c]=1;
	a[r][c]=cnt++;
	if(ch[r][c]=='S')
		dfs(r+1,c);
	else if(ch[r][c]=='N')
		dfs(r-1,c);
	else if(ch[r][c]=='E')
		dfs(r,c+1);
	else
		dfs(r,c-1);
}

int main()
{
	while(~scanf("%ld%ld%ld",&n,&m,&s)&&(n||m||s))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;j<m;j++)
				a[i][j]=visit[i][j]=0;
		}
		fg=0;
		cnt=0;
		dfs(0,s-1);
		if(fg)
			printf("%ld step(s) before a loop of %ld step(s)\n",v,cnt-v);
		else
			printf("%ld step(s) to exit\n",cnt);
	}
	return 0;
}

