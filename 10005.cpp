#include<stdio.h>
#include<math.h>

int main()
{
	double x,y,x1,y1,n,k,r,a,b,c,d;
	while(scanf("%lf",&n)&&n)
	{
		scanf("%lf%lf",&x,&y);
		x1=x;y1=y;
		for(k=2;k<=n;k++)
		{
			scanf("%lf%lf",&a,&b);
			x1+=a;
			y1+=b;
		}
		c=x1/n;
		d=y1/n;
		scanf("%lf",&r);
		if(sqrt((c-x)*(c-x)+(d-y)*(d-y))<=r)
			printf("The polygon can be packed in the circle.\n");
		else
			printf("There is no way of packing that polygon.\n");
	}
	return 0;
}