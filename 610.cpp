#include<stdio.h>
#define min(a,b) (a<b ?a:b)
#define si 1010
long res[si],df[si],visit[si],cnt,num,a[si][si],n,aa[si][si];

long dfs(long node,long p)
{
	visit[node]=1;
	df[node]=num++;
	long l=num,rec,i;
	for(i=1;i<=n;i++)
	{
		if(a[node][i]==1)
		{
			if(visit[i]==0&&i!=p)
			{
				visit[i]=1;
				rec=dfs(i,node);
				if(rec>df[node])
				{
					printf("%ld %ld\n",node,i);
					printf("%ld %ld\n",i,node);
					aa[i][node]=aa[node][i]=1;
				}
				else if(aa[i][node]==0)
				{
					aa[node][i]=1;
					printf("%ld %ld\n",node,i);
				}
				l=min(l,rec);
			}
			else if(i!=p)
			{
				l=min(l,df[i]);
				if(aa[i][node]==0)
				{
					printf("%ld %ld\n",node,i);
					aa[node][i]=1;
				}
			}
		}
	}
	return l;
}
int main()
{
	long j,e,i,u,v,x=1;
	while(~scanf("%ld%ld",&n,&e)&&(n||e))
	{
		while(e--)
		{
			scanf("%ld%ld",&u,&v);
			a[u][v]=a[v][u]=1;
		}
		num=1;
		printf("%ld\n\n",x++);
		dfs(1,-1);
		for(i=1;i<=n;i++)
		{
			res[i]=visit[i]=0;
			for(j=1;j<=n;j++)
				a[i][j]=aa[i][j]=0;
		}
		printf("#\n");
	}
	return 0;
}