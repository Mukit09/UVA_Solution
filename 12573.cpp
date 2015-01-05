#include<stdio.h>
#include<math.h>

long i,x,y,t,a,k,l,mn,b;

int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		if(y==x+2)
		{
			printf("%lld\n",x+1);
			continue;
		}
		y-=2;
		x-=y;
		b=sqrt(x);
		mn=x+10;
		l=mn;
		for(i=1;i<=b;i++)
		{
			if(x%i==0)
			{
				if(i>y)
				{
					mn=i;
					break;
				}
				k=x/i;
				if(k>y&&k<mn)
					mn=k;
			}
		}
		if(mn==l)
			printf("Impossible\n");
		else
			printf("%lld\n",mn);
	}
	return 0;
}