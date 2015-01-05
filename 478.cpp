#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define eps 1e-6

long fg,i,j,k,c,n;
double x,y,ab,bc,ca,s,sm;
char ch[10];
struct ss
{
	double x1,y1,x2,y2,xc,yc,r,flag,area;
}stru[15];

int main()
{
	long i=1;
	while(~scanf("%s",ch))
	{
		if(strcmp(ch,"*")==0)
			break;
		if(ch[0]=='r')
		{
			scanf("%lf%lf%lf%lf",&stru[i].x1,&stru[i].y1,&stru[i].x2,&stru[i].y2);
			stru[i].r=stru[i].xc=stru[i].yc=stru[i].flag=stru[i].area=0;
		}
		else if(ch[0]=='c')
		{
			scanf("%lf%lf%lf",&stru[i].xc,&stru[i].yc,&stru[i].r);
			stru[i].x1=stru[i].y1=stru[i].x2=stru[i].y2=stru[i].area=0;
			stru[i].flag=1;
		}
		else 
		{
			scanf("%lf%lf%lf%lf%lf%lf",&stru[i].x1,&stru[i].y1,&stru[i].x2,&stru[i].y2,&stru[i].xc,&stru[i].yc);
			stru[i].r=0;
			stru[i].flag=2;
			ab=sqrt((stru[i].x1-stru[i].x2)*(stru[i].x1-stru[i].x2)+(stru[i].y1-stru[i].y2)*(stru[i].y1-stru[i].y2));
			bc=sqrt((stru[i].x2-stru[i].xc)*(stru[i].x2-stru[i].xc)+(stru[i].y2-stru[i].yc)*(stru[i].y2-stru[i].yc));
			ca=sqrt((stru[i].xc-stru[i].x1)*(stru[i].xc-stru[i].x1)+(stru[i].yc-stru[i].y1)*(stru[i].yc-stru[i].y1));
			s=(ab+bc+ca)/2.0;
			stru[i].area=sqrt(s*(s-ab)*(s-bc)*(s-ca));
		}
		i++;
	}
	n=i;
	c=1;
	while(scanf("%lf%lf",&x,&y))
	{
		if(x==9999.9&&y==9999.9)
			break;
		fg=0;
		for(i=1;i<=n;i++)
		{
			if(stru[i].x1<x&&stru[i].x2>x&&stru[i].y1>y&&stru[i].y2<y&&stru[i].flag==0)
			{
				fg=1;
				printf("Point %ld is contained in figure %ld\n",c,i);
			}
			else if(sqrt((stru[i].xc-x)*(stru[i].xc-x)+(stru[i].yc-y)*(stru[i].yc-y))<stru[i].r&&stru[i].flag==1)
			{
				fg=1;
				printf("Point %ld is contained in figure %ld\n",c,i);
			}
			else if(stru[i].flag==2)
			{
				sm=0;
				ab=sqrt((stru[i].x1-x)*(stru[i].x1-x)+(stru[i].y1-y)*(stru[i].y1-y));
				bc=sqrt((x-stru[i].xc)*(x-stru[i].xc)+(y-stru[i].yc)*(y-stru[i].yc));
				ca=sqrt((stru[i].xc-stru[i].x1)*(stru[i].xc-stru[i].x1)+(stru[i].yc-stru[i].y1)*(stru[i].yc-stru[i].y1));
				s=(ab+bc+ca)/2.0;
				sm+=sqrt(s*(s-ab)*(s-bc)*(s-ca));

				ab=sqrt((x-stru[i].x2)*(x-stru[i].x2)+(y-stru[i].y2)*(y-stru[i].y2));
				bc=sqrt((stru[i].x2-stru[i].xc)*(stru[i].x2-stru[i].xc)+(stru[i].y2-stru[i].yc)*(stru[i].y2-stru[i].yc));
				ca=sqrt((stru[i].xc-x)*(stru[i].xc-x)+(stru[i].yc-y)*(stru[i].yc-y));
				s=(ab+bc+ca)/2.0;
				sm+=sqrt(s*(s-ab)*(s-bc)*(s-ca));

				ab=sqrt((stru[i].x1-stru[i].x2)*(stru[i].x1-stru[i].x2)+(stru[i].y1-stru[i].y2)*(stru[i].y1-stru[i].y2));
				bc=sqrt((stru[i].x2-x)*(stru[i].x2-x)+(stru[i].y2-y)*(stru[i].y2-y));
				ca=sqrt((x-stru[i].x1)*(x-stru[i].x1)+(y-stru[i].y1)*(y-stru[i].y1));
				s=(ab+bc+ca)/2.0;
				sm+=sqrt(s*(s-ab)*(s-bc)*(s-ca));
				if(fabs(sm-stru[i].area)<=eps)
				{
					fg=1;
					printf("Point %ld is contained in figure %ld\n",c,i);
				}
			}
		}
		if(!fg)
			printf("Point %ld is not contained in any figure\n",c);
		c++;
	}
	return 0;
}