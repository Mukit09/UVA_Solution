#include<stdio.h>
#define inf -99999999

long n,i,mx,start,end,mx_sm,cur_start,a[20010],t,x=1;
int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=1;i<n;i++)
			scanf("%ld",&a[i]);
		mx=inf;
		mx_sm=0;
		start=cur_start=1;

		for(i=1;i<n;i++)
		{
			mx_sm+=a[i];
			if(mx<mx_sm||(mx==mx_sm)&&(end-start)<(i-cur_start))
			{
				mx=mx_sm;
				end=i;
				start=cur_start;
			}
			if(mx_sm<0)
			{
				mx_sm=0;
				cur_start=i+1;
			}
		}
		if(mx>0)
			printf("The nicest part of route %ld is between stops %ld and %ld\n",x++,start,end+1);
		else
			printf("Route %ld has no nice parts\n",x++);
	}
	return 0;
}