#include<stdio.h>
#include<string.h>

long a[100];
char ch[20][20];
char re[20][20];
char st;

void dfs(long r,long c)
{
	if(ch[r][c]!='.'||c<0||r<0||c>=9||r>=9)
	{
		if(ch[r][c]!='.')
			a[ch[r][c]]++;
		return ;
	}
	ch[r][c]='*';
	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main()
{
	long i,j,b,w,t,k;
	scanf("%ld",&t);
	while(t--)
	{
		for(i=0;i<9;i++)
		{
			scanf("%s",ch[i]);
			strcpy(re[i],ch[i]);
		}
		b=w=0;
		
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(ch[i][j]=='O')
					w++;
				else if(ch[i][j]=='X')
					b++;
				else
				{
					a['X']=a['O']=0;
					dfs(i,j);
					if(a['X']==0&&a['O']!=0)
						w++;
					else if(a['X']!=0&&a['O']==0)
						b++;
					for(k=0;k<9;k++)
						strcpy(ch[k],re[k]);
				}
			}
		}
		printf("Black %ld White %ld\n",b,w);
	}
	return 0;
}

