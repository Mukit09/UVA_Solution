#include<stdio.h>
#include<string.h>

char ch[101][101];
char re[101][101];
long count,row,colm;

void dfs(long r,long c)
{
	if(r<0||c<0||r>=row||c>=colm||re[r][c]=='L')
		return ;

	re[r][c]='L';
	count++;

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
	long t,x,y,fg,i,fg1,j;
	scanf("%ld",&t);
	while(t--)
	{
		fg=i=0;
		while(1)
		{
			count=0;
			scanf("%s",ch[i]);
			if(ch[i][0]>=48&&ch[i][0]<58)
				break;
			i++;
         }
		row=i;fg=fg1=0;
		colm=strlen(ch[i-1]);
		while(1)
		{
			if(!fg)
			{
				for(j=0;j<row;j++)
					strcpy(re[j],ch[j]);
				count=0;
				sscanf(ch[i],"%ld",&x);
				scanf("%ld",&y);
				dfs(x-1,y-1);
				printf("%ld\n",count);
				getchar();
				fg=1;
			}	 
			else
			{
				while(gets(ch[i]))
				{
					if(strcmp(ch[i],"")==0)
						break;
					for(j=0;j<row;j++)
						strcpy(re[j],ch[j]);
					count=0;
					sscanf(ch[i],"%ld%ld",&x,&y);
					dfs(x-1,y-1);
					printf("%ld\n",count);
					fg1=1;
				}
			}
			if(fg1)
				break;
		}
        
        if(t)
			printf("\n");
	}
	return 0;
}
