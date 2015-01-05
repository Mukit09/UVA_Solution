#include<stdio.h>
#include<queue>

using namespace std;

queue<long>q;

long a[150][150],in[150];

int main()
{
	long i,j,flag,x,n,e,u,v;
	while(scanf("%ld%ld",&n,&e)&&(n||e))
	{

		flag=0;
		for(i=1;i<=100;i++)
			in[i]=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=9999999;
				}
			}
		}

		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			a[u][v]=1;
			in[v]++;
		}

		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				flag=1;
				q.push(i);
			}
		}
		while(flag&&q.empty()==0)
		{
			x=q.front();
			q.pop();
			for(i=1;i<=n;i++)
			{
				if(a[x][i]==1)
				{
					in[i]--;
					if(in[i]==0)
					{
						q.push(i);
					}
				}
			}
			if(q.empty()==1)
				printf("%ld",x);
			else
				printf("%ld ",x);
		}
		printf("\n");
	}
	return 0;
}