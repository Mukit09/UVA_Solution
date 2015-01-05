#include<stdio.h>

long dp[40][1010],dir[40][1010],v[40],d[40],t,n,w,x[40],k,fg=0;

long rec(long i,long taken)
{
	if(i>n||taken>t)
		return 0;
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	long p1=0,p2;
	if(d[i]+taken<=t)
		p1=v[i]+rec(i+1,d[i]+taken);
	p2=rec(i+1,taken);
	if(p1>p2)
	{
		dp[i][taken]=p1;
		dir[i][taken]=1;
		k++;
	}
	else
	{
		dp[i][taken]=p2;
		dir[i][taken]=2;
	}
	return dp[i][taken];
}

void path_print(long i,long taken)
{
	if(i>n||taken>t)
		return ;
	if(dir[i][taken]==1)
	{
		x[k++]=i;
		path_print(i+1,taken+d[i]);
	}
	else if(dir[i][taken]==2)
		path_print(i+1,taken);
	else
		return ;
}

int main()
{
	long i,j,sm;
	while(~scanf("%ld%ld",&t,&w))
	{
		if(fg)
			printf("\n");
		fg=1;
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%ld%ld",&d[i],&v[i]);
			d[i]*=w;
			d[i]+=(2*d[i]);
			for(j=0;j<=t;j++)
			{
				dir[i][j]=-1;
				dp[i][j]=-1;
			}
		}
		sm=rec(1,0);
		printf("%ld\n",sm);
		k=1;
		path_print(1,0);
		printf("%ld\n",k-1);
		for(i=1;i<k;i++)
			printf("%ld %ld\n",d[x[i]]/(w*3),v[x[i]]);
	}
	return 0;
}