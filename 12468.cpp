#include<stdio.h>
#include<math.h>

long a,b,d;

int main()
{
	while(~scanf("%ld%ld",&a,&b))
	{
		if(a==-1&&b==-1)
			break;
		d=abs(b-a);
		if(100-d<d)
			d=100-d;
		printf("%ld\n",d);
	}
	return 0;
}