#include<stdio.h>
#include<math.h>
#define max(a,b)(a>b ?a:b)
#define min(a,b)(a<b ?a:b)

int main()
{
	long x,y,xx,yy,x1,y1,x2,y2,x3,y3,x4,y4,t;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld%ld",&x1,&y1,&x2,&y2);
		scanf("%ld%ld%ld%ld",&x3,&y3,&x4,&y4);
		if((x1<x3&&x2<=x3)||(x3<x1&&x4<=x1)||(y3>=y2&&y4>y2)||(y3<y1&&y4<=y1))
			printf("No Overlap\n");
		else
		{
			x=max(x1,x3);
			xx=min(x2,x4);
			y=max(y1,y3);
			yy=min(y2,y4);
			printf("%ld %ld %ld %ld\n",x,y,xx,yy);
		}
		if(t)
			printf("\n");
	}
	return 0;
}