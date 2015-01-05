#include<stdio.h>

int main()
{
	long long m,x,u,v;
	while(scanf("%lld%lld",&m,&x)&&(m||x))
	{
		if(x==0||x==100||m==1)
		{
			printf("Not found\n");
			continue;
		}
		u=((m-1)*100)/(100-x);
		v=((m-1)*100)%(100-x);
		if(v==0)
			u--;
		if(u<m)
			printf("Not found\n");
		else
			printf("%lld\n",u);
	}
	return 0;
}