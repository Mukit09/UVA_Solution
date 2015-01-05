#include<stdio.h>
int a[40],taken[20],res[20],n,x;

void rec(int ind)
{
	int i;
	if(ind==n+1)
	{
		printf("1");
		for(i=2;i<=n;i++)
			printf(" %d",res[i]);
		printf("\n");
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			if(!taken[i]&&((x<n&&a[i+res[x-1]]==1)||(x==n&&a[i+1]==1&&a[i+res[x-1]]==1
				)))
			{
				taken[i]=1;
				res[x++]=i;
				rec(x);
				taken[i]=0;
				x--;
			}
		}
	}
}

int main()
{
	int k=1,fg=1;
	a[2]=a[3]=a[5]=a[7]=a[11]=a[13]=a[17]=a[19]=a[23]=a[29]=a[31]=1;
	while(~scanf("%d",&n))
	{
		if(!fg)
			printf("\n");
		fg=0;
		printf("Case %d:\n",k++);
		x=1;
		res[x++]=1;
		rec(x);
	}
	return 0;
}