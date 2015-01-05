#include<stdio.h>

int main()
{
	long i,j,a,b,node[150],edge=0,q[150][150],cs=1,k,check[150],x;
	double re;
	while(scanf("%ld%ld",&a,&b)&&(a||b))
	{
		k=q[a][b]=1;
		edge++;
		for(i=1;i<=100;i++)
			check[i]=0;
		check[a]=1;
		node[k++]=a;
		check[b]=1;
		node[k++]=b;
		while(scanf("%ld%ld",&a,&b)&&(a||b))
		{
			q[a][b]=1;
			edge++;
			if(check[a]==0)
			{
				check[a]=1;
				node[k++]=a;
			}
			if(check[b]==0)
			{
				check[b]=1;
				node[k++]=b;
			}

		}
		k--;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(i==j)
				{
					q[node[i]][node[j]]=0;
				}
				else if(q[node[i]][node[j]]!=1)
				{
					q[node[i]][node[j]]=9999999;
				}
			}
		}

		for(x=1;x<=k;x++)
		{
			for(i=1;i<=k;i++)
			{
				for(j=1;j<=k;j++)
				{
					if((q[node[i]][node[j]]>q[node[i]][node[x]]+q[node[x]][node[j]])&&i!=j)
					{
						q[node[i]][node[j]]=q[node[i]][node[x]]+q[node[x]][node[j]];
					}
				}
			}
		}

		re=0;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(i!=j)
				{
					re+=q[node[i]][node[j]];
					q[node[i]][node[j]]=0;
				}
				else
					q[node[i]][node[j]]=0;

			}
		}
		re/=(k*(k-1));
		printf("Case %ld: average length between pages = %.3lf clicks\n",cs++,re);
		edge=0;
	}
	return 0;
}