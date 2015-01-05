#include<stdio.h>
#define mx 99999999

long i,k,w[110][110],u,v,c,q,c1,c2,s,j,d,t=1,fg=0;

long min(long a,long b)
{
	if(a<b)
		return a;
	else return b;
}

long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}
int main()
{
	while(~scanf("%ld%ld%ld",&c,&s,&q)&&(s||q||c))
	{
		for(i=1;i<=c;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(i==j)
					w[i][j]=0;
				else
					w[i][j]=mx;
			}
		}
		for(i=1;i<=s;i++)
		{
			scanf("%ld%ld%ld",&c1,&c2,&d);
			w[c1][c2]=w[c2][c1]=d;
		}
		for(k=1;k<=c;k++)
		{
			for(i=1;i<=c;i++)
			{
				for(j=1;j<=c;j++)
				{
					w[i][j]=min(w[i][j],max(w[i][k],w[k][j]));
				}
			}
		}
		if(fg)
			printf("\n");
		fg=1;
		printf("Case #%ld\n",t++);
		for(i=1;i<=q;i++)
		{
			scanf("%ld%ld",&u,&v);
			if(w[u][v]==mx)
				printf("no path\n");
			else
				printf("%ld\n",w[u][v]);
		}
	}
	return 0;
}
