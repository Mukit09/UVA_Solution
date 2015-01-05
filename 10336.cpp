#include<stdio.h>
#include<string.h>

char ch[2500][2000],st;
long h,w;
long a[150];

void dfs(long r,long c)
{
	if(r<0||c<0||r>=h||c>=w||ch[r][c]!=st)
		return ;

	ch[r][c]='.';

	dfs(r+1,c);
	dfs(r-1,c);
	dfs(r,c+1);
	dfs(r,c-1);
}

int main()
{
	long i,j,t,k=1,max;
	scanf("%ld",&t);
	while(t--)
	{
		for(i=90;i<=130;i++)
			a[i]=0;

		scanf("%ld%ld",&h,&w);
		for(i=0;i<h;i++)
			scanf("%s",ch[i]);

		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(ch[i][j]>=97&&ch[i][j]<=122)
				{
					st=ch[i][j];
					a[ch[i][j]]++;
					dfs(i,j);
				}
			}
		}

		printf("World #%ld\n",k++);
		while(1)
		{
			max=0;
			for(i=97;i<=122;i++)
			{
				if(a[i]>max)
					max=a[i];
			}
			if(max==0)
				break;
			for(i=97;i<=122;i++)
			{
				if(a[i]==max)
				{
					printf("%c: %ld\n",i,max);
					a[i]=0;
				}
			}
		}
	}
	return 0;
}