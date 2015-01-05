#include<stdio.h>
char ch[20];
long x=1;

int main()
{
	while(gets(ch))
	{
		if(ch[0]=='*')
			break;
		if(ch[0]=='H')
			printf("Case %ld: Hajj-e-Akbar\n",x++);
		else
			printf("Case %ld: Hajj-e-Asghar\n",x++);
	}
	return 0;
}