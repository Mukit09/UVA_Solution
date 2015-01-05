#include<stdio.h>
#include<math.h>

int main()
{
	double r1,r2,r3,t,a,b,c,A,B,C,ar,ar1,ar2,ar3,result,p,q,r;
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a=r1+r2;
		b=r2+r3;
		c=r3+r1;
		p=a*a;
		q=b*b;
		r=c*c;
		A=acos((q+r-p)/(2*b*c));
		B=acos((p+r-q)/(2*a*c));
		C=acos((p+q-r)/(2*b*a));
		ar=0.5*a*c*sin(B);
		ar1=0.5*B*r1*r1;
		ar2=0.5*C*r2*r2;
		ar3=0.5*A*r3*r3;
		result=ar-(ar1+ar2+ar3);
		printf("%.6lf\n",result);
	}
	return 0;
}