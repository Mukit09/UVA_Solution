#include<stdio.h>

int main()
{
	long h,m,s,ms,ds,re,i,count;
	char ch[15];
	while(scanf("%s",ch)==1)
	{
		h=(ch[0]-48)*10+(ch[1]-48);
		m=(ch[2]-48)*10+(ch[3]-48);
		s=(ch[4]-48)*10+(ch[5]-48);
		ms=(ch[6]-48)*10+(ch[7]-48);

		ds=(h*3600+m*60+s)*100+ms;
		ds*=125;
		ds/=108;
		re=ds;
		count=0;
		while(re!=0)
		{
			re/=10;
			count++;
		}
		for(i=1;i<=(7-count);i++)
			printf("0");
		if(ds)
			printf("%ld",ds);
		printf("\n");
	}
	return 0;
}