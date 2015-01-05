#include<stdio.h>

int main()
{
	long a,b,t,cnt_a,cnt_b,step;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		cnt_a=cnt_b=0;
		step=0;
		while(b-a>0)
		{
			if(b-a>cnt_a)
				cnt_a++;
			a+=cnt_a;
			step++;
			if(b-a<=0)
				break;
			if(b-a>cnt_b)
				cnt_b++;
			b-=cnt_b;
			step++;
		}
		printf("%ld\n",step);
	}
	return 0;
}
