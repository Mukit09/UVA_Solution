#include<stdio.h>

int main()
{
	char ch[100];
	long t,n,sum=0;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",ch);
		if(ch[0]=='d')
		{
			scanf("%ld",&n);
			sum+=n;
		}
		else
			printf("%ld\n",sum);
	}
	return 0;
}