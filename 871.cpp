#include<stdio.h>
#include<string.h>

char ch[30][30];
long count,k,l;

void dfs(long r,long c)
{
	if(r<0||c<0||r>=k||c>=l||ch[r][c]==48)
	{
		return ;
	}
	if(ch[r][c]==49)
	{
		count++;
		ch[r][c]=48;
	}

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
	long t,i,j,max;
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t--)
	{
		max=count=k=0;
		while(gets(ch[k]))
		{
			if(strcmp(ch[k],"")==0)
				break;
			k++;
		}
		for(i=0;i<k;i++)
		{
			l=strlen(ch[i]);
			for(j=0;j<l;j++)
			{
				if(ch[i][j]==49)
				{
					dfs(i,j);
					if(count>max)
						max=count;
					count=0;
				}
			}
		}
		printf("%ld\n",max);
		if(t)
			printf("\n");
	}
	return 0;
}