#include<stdio.h>
#include<math.h>

int main()
{
	int n,i,a;
	long long xr;
	while(~scanf("%d",&n)&&n)
	{
		xr=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			xr=xr^a;
		}
		if(xr)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}