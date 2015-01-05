#include<stdio.h>
#include<string.h>

char ch[110][110];
char d[50010];
char si[]={'N','L','S','O'};
char c;
long cnt,n,m,s,a,b,p,l;

int main()
{
	long i,j;
	while(~scanf("%ld%ld%ld",&n,&m,&s)&&(n||m||s))
	{
		cnt=1;
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			if(cnt)
			{
				for(j=0;ch[i][j];j++)
				{
					if(ch[i][j]=='N'||ch[i][j]=='S'||ch[i][j]=='L'||ch[i][j]=='O')
					{
						c=ch[i][j];
						a=i,b=j;
						cnt=0;
						break;
					}
				}
			}
		}
		scanf("%s",d);
		for(i=0;i<4;i++)
		{
			if(c==si[i])
			{
				p=i;
				break;
			}
		}
		l=strlen(d);
		for(i=0;i<l;i++)
		{
			if(d[i]=='D')
			{
				p++;
				p%=4;
			}
			else if(d[i]=='E')
			{
				p--;
				if(p<0)
					p+=4;
			}
			else if(d[i]=='F')
			{
				if(p==0)
				{
					if(a-1>=0&&ch[a-1][b]!='#')
						a--;
				}
				else if(p==1)
				{
					if(b+1<m&&ch[a][b+1]!='#')
						b++;
				}
				else if(p==2)
				{
					if(a+1<n&&ch[a+1][b]!='#')
						a++;
				}
				else if(p==3)
				{
					if(b-1>=0&&ch[a][b-1]!='#')
						b--;
				}
				if(ch[a][b]=='*')
				{
					cnt++;
					ch[a][b]='.';
				}
			}	
		}
		printf("%ld\n",cnt);
	}
	return 0;
}