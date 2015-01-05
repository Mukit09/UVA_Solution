#include<stdio.h>
#include<string.h>

char ch[15][15],str[15][15];

int main()
{
	long i,j,t,n,cnt,fg;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%s",ch[i]);
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		fg=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(str[i][j]=='x')
				{
					cnt=0;
					if((i+1<n)&&(j+1<n)&&ch[i+1][j+1]=='*')
						cnt++;
					if((i+1<n)&&(j-1>=0)&&ch[i+1][j-1]=='*')
						cnt++;
					if((i+1<n)&&ch[i+1][j]=='*')
						cnt++;
					if((i-1>=0)&&ch[i-1][j]=='*')
						cnt++;
					if((i-1>=0)&&(j+1<n)&&ch[i-1][j+1]=='*')
						cnt++;
					if((i-1>=0)&&(j-1>=0)&&ch[i-1][j-1]=='*')
						cnt++;
					if((j+1<n)&&ch[i][j+1]=='*')
						cnt++;
					if((j-1>=0)&&ch[i][j-1]=='*')
						cnt++;
					str[i][j]=cnt+48;
					if(ch[i][j]=='*')
						fg=1;
				}
			}
		}
		if(fg)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(ch[i][j]=='*')
						str[i][j]='*';
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%s\n",str[i]);
		if(t)
			puts("");
	}
	return 0;
}