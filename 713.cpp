#include<stdio.h>
#include<string.h>
char a[1000000],c[1000000],d[1000000];
long i,lc,ld,j,car,T;
int main()
{
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%s%s",c,d);
		lc=strlen(c);
		ld=strlen(d);
		for(i=lc;i<=ld;i++)
			c[i]=48;
		for(i=ld;i<=lc;i++)
			d[i]=48;
		if(lc<ld)
			lc=ld;
		car=0;
		for(i=0;i<lc;i++)
		{
			a[i]=(c[i]+d[i]+car)-48;
			car=0;
			if(a[i]>57)
			{
				a[i]-=10;
				car=1;
			}
		}
		if(car==1)
		{
			a[i]=49;
			i++;
		}
		a[i]=0;
		lc=i;
		i=0;
		while(a[i]=='0' && i<lc-1)
			i++;
		for(;i<lc;i++)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}