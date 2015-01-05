#include<stdio.h>
#include<math.h>
#define pi 3.1415926535

int main()
{
	double h1,v,ar,w,h,l,r,an;
	while(~scanf("%lf%lf%lf%lf",&l,&w,&h,&r))
	{
		an=(r*pi)/180;
		v=l*w*h;
		h1=l*tan(an);
		if(h1<=h)
		{
			ar=0.5*h1*l*w;
			v=v-ar;
		}
		else
		{
			an=((90-r)*pi)/180;
			h1=h*tan(an);
			v=0.5*h1*h*w;
		}
		printf("%.3lf mL\n",v);
	}
	return 0;
}