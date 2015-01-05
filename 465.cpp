#include<stdio.h>

int main()
{
	long double a,b,c;
	char ch,ch1[1010],ch2[1010];
	while(scanf("%s %c %s",ch1,&ch,ch2)==3)
	{
		printf("%s %c %s\n",ch1,ch,ch2);
		sscanf(ch1,"%llf",&a);
		sscanf(ch2,"%llf",&b);
		if(a>2147483647)
			printf("first number too big\n");
		if(b>2147483647)
			printf("second number too big\n");
		if(ch=='+')
			c=a+b;
		else if(ch=='*')
			c=a*b;
		if(c>2147483647)
			printf("result too big\n");
	}
	return 0;
}