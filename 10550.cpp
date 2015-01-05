#include<stdio.h>

int main()
{
	long a,b,c,d,e,f;
	while(scanf("%ld%ld%ld%ld",&a,&b,&c,&d))
	{
		if(a==0&&b==0&&c==0&&d==0)
			break;
		e=1080;
		f=40+a;
		f=f-b;
		if(f>40)
		{
			f-=40;
		}
		e=e+f*9;
		f=40+c;
		f=f-b;
		if(f>40)
		{
			f-=40;
		}
		e=e+f*9;
		f=40+c;
		f=f-d;
		if(f>40)
		{
			f-=40;
		}
		e=e+f*9;
		printf("%ld\n",e);
	}
	return 0;
}