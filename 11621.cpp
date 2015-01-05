#include<stdio.h>
#include<math.h>

long double i,j,n,a,b;

int main()
{
	long double min;
	while(~scanf("%llf",&n)&&n)
	{
		for(i=0;i<=31;i++)
		{
			a=pow(2,i);
			if(a>=n)
				break;
		}
		min=a;
		for(i=0;i<=20;i++)
		{
			a=pow(3,i);
			if(a>=n)
				break;
		}
		if(min>a)
			min=a;
		for(i=0;i<=31;i++)
		{
			for(j=0;j<=20;j++)
			{
				a=pow(2,i);
				b=pow(3,j);
				if(a*b>=n)
					break;
			}	
			if(min>a*b)
				min=a*b;
		}
		printf("%.0llf\n",min);
	}
	return 0;
}
