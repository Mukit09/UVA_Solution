#include<stdio.h>
#include<string.h>

char ch[1500][1500],st;
long l,row,colm,count;
long a[1500][1500],chk[1500];

void dfs(long r,long c)
{
	if(r>=row||c>=colm||r<0||c<0||ch[r][c]!=st)
		return;
	
	ch[r][c]='.';
	a[r][c]=count;

	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+2);
	dfs(r,c-2);
	dfs(r+1,c+2);
	dfs(r-1,c-2);
	dfs(r+1,c-2);
	dfs(r-1,c+2);
}

int main()
{
	long i=0,j,max,q;
	char c='%';
	while(gets(ch[i++]))
	{
		while(gets(ch[i++]))
		{
			if(strcmp(ch[i-1],"%")==0)
				break;
		}
		row=i-1;
		count=1;
		for(i=0;i<row;i++)
		{
			colm=strlen(ch[i]);
			for(j=0;j<colm;j++)
			{
				if((ch[i][j]>=65&&ch[i][j]<=90)||(ch[i][j]>=97&&ch[i][j]<=122))
				{
					st=ch[i][j];
					dfs(i,j);
					count++;
				}
				chk[j]=0;
			}		
		}

		for(i=0;i<colm;i++)
		{
			max=0;
			for(j=0;j<row;j++)
			{
				if(max<a[j][i])
					max=a[j][i];
			}
			while(max!=0)
			{
				chk[i]++;
				max/=10;
			}
		}
					
		for(i=0;i<row;i++)
		{
			colm=strlen(ch[i]);
			printf("%*ld",chk[0],a[i][0]);
			for(j=1;j<colm;j++)
			{
				if(ch[i][j]!=32)
					printf(" %*ld",chk[j],a[i][j]);
			}
			printf("\n");
		}
		printf("%c\n",c);
		i=0;	
	}
	return 0;
}
