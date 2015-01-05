#include<stdio.h>
#include<string.h>

char ch[15];
long dp[100100],a[100100],dir[100100],n;

long longest(long u)
{
	if(u>n)
		return 0;
	if(dp[u]!=-1)
		return dp[u];
	long v,p,mx=0;
	for(v=u+1;v<=n;v++)
	{
		if(a[v]>a[u])
		{
			p=longest(v);
			if(mx<p)
			{
				mx=p;
				dir[u]=v;
			}
		}
	}
	dp[u]=mx+1;
	return dp[u];
}

void path_print(long start)
{
	while(1)
	{
		printf("%ld\n",a[start]);
		if(dir[start]==-1)
			break;
		start=dir[start];
	}
}

int main()
{
	long t,i,mx,start,p;
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t--)
	{
		i=1;
		while(gets(ch))
		{
			if(strcmp(ch,"")==0)
				break;
			dp[i]=dir[i]=-1;
			sscanf(ch,"%ld",&a[i++]);
		}
		n=i-1;
		mx=0;
		for(i=1;i<=n;i++)
		{
			p=longest(i);
			if(mx<p)
			{
				mx=p;
				start=i;
			}
		}
		printf("Max hits: %ld\n",mx);
		path_print(start);
		if(t)
			printf("\n");
	}
	return 0;
}
