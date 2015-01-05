#include<stdio.h>
#include<algorithm>

using namespace std;

char ch[150][60];
long w,h,cnt;
long a[15];

void dfs1(long x,long y)
{
	if(x<0||y<0||x>=h||y>=w||ch[x][y]!='X')
		return ;
	ch[x][y]='*';

	dfs1(x+1,y);
	dfs1(x-1,y);
	dfs1(x,y+1);
	dfs1(x,y-1);
}

void dfs(long r,long c)
{
	if(r<0||c<0||r>=h||c>=w||ch[r][c]=='.')
		return ;
	if(ch[r][c]=='X')
	{
		dfs1(r,c);
		cnt++;
	}
	ch[r][c]='.';
	
	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main()
{
	long i,j,k=1,x;
	while(~scanf("%ld%ld",&w,&h)&&(w||h))
	{
		x=0;
		for(i=0;i<h;i++)
			scanf("%s",ch[i]);

		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(ch[i][j]=='*')
				{
					cnt=0;
					dfs(i,j);
					a[x++]=cnt;
				}
			}
		}
		printf("Throw %ld\n",k++);
		sort(a,a+x);
		printf("%ld",a[0]);
		for(i=1;i<x;i++)
			printf(" %ld",a[i]);
		printf("\n");
		printf("\n");
	}
	return 0;
}