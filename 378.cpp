#include<stdio.h>

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,t,i,x,y;
	scanf("%lf",&t);
	printf("INTERSECTING LINES OUTPUT\n");
	for(i=1;i<=t;i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if((x1==x2)&&(x2==x3)&&(x3==x4))
			printf("LINE\n");
		else if(((y1-y3)/(x1-x3))==((y2-y4)/(x2-x4))&&((y1-y3)/(x1-x3))==((y2-y3)/(x2-x3)))
			printf("LINE\n");
		else
		{
			if(x1==x2&&x3==x4)
			{
				printf("NONE\n");
			}
			else if(((y1-y2)/(x1-x2))==((y3-y4)/(x3-x4)))
				printf("NONE\n");
			else
			{
				x=((x2*y1-x1*y2)*(x3-x4)-(x4*y3-x3*y4)*(x1-x2))/((y4-y3)*(x1-x2)-(y2-y1)*(x3-x4));
				y=((x2*y1-x1*y2)*(y4-y3)-(x4*y3-x3*y4)*(y2-y1))/((x3-x4)*(y2-y1)-(x1-x2)*(y4-y3));
				printf("POINT %.2lf %.2lf\n",x,y);
			}
		}

	}
	printf("END OF OUTPUT\n");
	return 0;
}
