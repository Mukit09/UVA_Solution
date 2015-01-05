#include<stdio.h>
#define inf -9999999

long i,n,mx_sm,mx,start,end,cur_start,a[10010];
int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		start=cur_start=1;
		mx=inf;
		mx_sm=0;
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=n;i++)
		{
			mx_sm+=a[i];
			if(mx<mx_sm)
			{
				mx=mx_sm;
				start=cur_start;
				end=i;
			}
			if(mx_sm<0)
			{
				mx_sm=0;
				cur_start=i+1;
			}
		}
		if(mx<=0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %ld.\n",mx);
	}
	return 0;
}