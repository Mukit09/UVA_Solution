#include<stdio.h>

int main()
{
	long n,i,a[20],c,min,j;
	char ch[30];
	while(scanf("%ld",&n)&&n)
	{
		getchar();
		min=25;
		for(i=1;i<=n;i++)
		{
			gets(ch);
			c=0;
			for(j=0;j<25;j++)
			{
				if(ch[j]==48||ch[j]==32)
					c++;
			}
			if(c<min)
				min=c;
			a[i]=c;
		}
		c=0;
		for(i=1;i<=n;i++)
			c+=a[i]-min;
		printf("%ld\n",c);
	}
	return 0;
}
