#include<stdio.h>
#include<math.h>
#define pi acos(-1)
long t;
double l,r,cir,w;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%lf",&l);
		r=l/5;
		cir=pi*r*r;
		w=(6*l)/10;
		printf("%.2lf %.2lf\n",cir,(l*w)-cir);
	}
	return 0;
}