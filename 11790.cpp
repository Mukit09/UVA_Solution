#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define si 1502

int w[si],a[si],lis[si],lds[si];

int main()
{
	int t,n,i,j,mx,mx1,x=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);

		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);
		mx=mx1=0;
		for(i=1;i<=n;i++)
		{
			lis[i]=w[i];
			lds[i]=w[i];
			for(j=1;j<i;j++)
			{
				if(a[j]<a[i])
					lis[i]=max(lis[i],w[i]+lis[j]);
				else if(a[j]>a[i])
					lds[i]=max(lds[i],w[i]+lds[j]);
			}
			if(lis[i]>mx)
				mx=lis[i];
			if(lds[i]>mx1)
				mx1=lds[i];
		}
		if(mx>=mx1)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",x++,mx,mx1);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",x++,mx1,mx);
	}
	return 0;
}