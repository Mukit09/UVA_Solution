#include<stdio.h>

int n,m,e,a[15][15],out[15],visit[15],fg,taken[15];

void rec(int node,int l)
{
	int i;
	if(l==e+1)
	{
		printf("(1");
		for(i=1;i<l;i++)
			printf(",%d",out[i]);
		printf(")\n");
		fg=1;
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(a[node][i]==1&&taken[i]==0)
		{
			taken[i]=1;
			out[l]=i;
			rec(i,l+1);
			taken[i]=0;
		}
	}
}

int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		if(n==-9999)
		{
			printf("\n");
			continue;
		}
		scanf("%d",&e);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
			taken[i]=0;
		}
		fg=0;
		taken[1]=1;
		rec(1,1);
		if(!fg)
			printf("no walk of length %d\n",e);
	}
	return 0;
}