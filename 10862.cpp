#include<stdio.h>
#include<string.h>
char a[1100],b[1100],c[1100],d[5001][1100];
long i,la,car,n;
int main()
{
	strcpy(d[0],"0");
	strcpy(d[1],"1");
	strcpy(d[2],"1");
	strcpy(a,"1");
	strcpy(b,"1");
	
	for(n=3;n<5001;n++)
	{
		la=strlen(a);
		car=0;
		for(i=0;i<la;i++)
		{
			if(a[i]<48)
				a[i]+=48;
			if(b[i]<48)
				b[i]+=48;
			c[i]=(a[i]-48)+(b[i]-48)+car;
			c[i]=c[i]+48;
			car=0;
			if(c[i]>57)
			{
				c[i]-=10;
				car=1;
			}
		}
		if(car==1)
		{
			c[i]=49;
			i++;
		}
		c[i]='\0';
		strcpy(d[n],c);
		strcpy(b,a);
		strcpy(a,c);
	}
	while(scanf("%ld",&n)&&n)
	{
		n*=2;
		la=strlen(d[n]);

		for(i=la-1;i>=0;i--)
			printf("%c",d[n][i]);
		printf("\n");
	}
	return 0;
}