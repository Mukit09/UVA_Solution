#include<stdio.h>
#include<math.h>
#include<string.h>

long fg,i,j,k,c,n;
double x,y;
char ch[10];
struct ss
{
	double x1,y1,x2,y2,xc,yc,r,flag;
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
			stru[i].r=stru[i].xc=stru[i].yc=stru[i].flag=0;
		}
		else
		{
			scanf("%lf%lf%lf",&stru[i].xc,&stru[i].yc,&stru[i].r);
			stru[i].x1=stru[i].y1=stru[i].x2=stru[i].y2=0;
			stru[i].flag=1;
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
		}
		if(!fg)
			printf("Point %ld is not contained in any figure\n",c);
		c++;
	}
	return 0;
}