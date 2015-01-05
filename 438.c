#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,x1,t,u,r,s,p,q,a,b,c,d,e,f,g,h,m1,m2,m3,m4,m5,m6,m7,r1,r2,r3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&t,&u,&r,&s,&p,&q)!=EOF)
	{
	m=(t-p)*(q-s);
	n=(r-p)*(q-u);
	a=m-n;
    b=(p*p+q*q);
	c=(q-s)-(q-u);
	h=b*c;
	d=(t*t+u*u)*(q-s);
	e=(r*r+s*s)*(q-u);
	f=d-e;
	g=f-h;
	x1=g/(2*a);
	m1=(t-p)-(r-p);
	m2=b*m1;
	m3=(r*r+s*s)*(t-p);
	m4=(t*t+u*u)*(r-p);
	m5=m3-m4;
	m6=m2-m5;
	m7=m6/(2*a);
	r1=pow((x1-t),2);
	r2=pow((m7-u),2);
	r3=sqrt(r1+r2);
	printf("%.2lf\n",2*3.14159265358979323846*r3);
	}
	return 0;
	}