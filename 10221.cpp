#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	double a,b,angle,c,dis,e,f,g,d;
	char ch1[10];
	while(scanf("%lf %lf %s",&dis,&angle,&ch1)!=EOF)
	{
		if(strcmp(ch1,"deg")==0)
		{
			if(angle>=180)
			{angle=360-angle;}
			a=(3.14159265358979323846*angle)/180;
			b=(6440+dis);
			c=b*a;
			d=2*(b*b);
			e=2*(b*b)*cos(a);
			f=d-e;
			g=sqrt(f);
			printf("%.6lf %.6lf\n",c,g);
		}
		else if(strcmp(ch1,"min")==0)
		{
			angle=angle/60;
			if(angle>=180)
			{angle=360-angle;}
			a=(3.14159265358979323846*angle)/180;
			b=(6440+dis);
			c=b*a;
			d=2*(b*b);
			e=2*(b*b)*cos(a);
			f=d-e;
			g=sqrt(f);
			printf("%.6lf %.6lf\n",c,g);
		}

	}
return 0;
}
