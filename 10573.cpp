#include<stdio.h>
#include<math.h>

#define pi 2*acos(0)

int main()
{
	double T,r1,r2,r,ar,ar1,ar2;
	char c;
	scanf("%lf",&T);
	while(T--)
	{
		scanf("%lf%c",&r1,&c);
		if(c==' ')
		{
			scanf("%lf",&r2);
			r=r1+r2;
			ar=pi*(r*r);
			ar1=pi*r1*r1;
			ar2=pi*r2*r2;
			printf("%.4lf\n",ar-(ar2+ar1));
		}
		else
		{
			ar=(pi*r1*r1)/8;
			printf("%.4lf\n",ar);
		}
	}
	return 0;
}