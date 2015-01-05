#include<stdio.h>

char ch[10];

int main()
{
	long top,n,north,south,west,east,i;
	while(~scanf("%ld",&n)&&n)
	{
		top=1,north=2,south=5,east=4,west=3;
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch);
			if(ch[0]=='n')
			{
				north=top;
				top=south;
				south=7-north;
			}
			else if(ch[0]=='s')
			{
				south=top;
				top=north;
				north=7-south;
			}
			else if(ch[0]=='e')
			{
				east=top;
				top=west;
				west=7-east;
			}
			else
			{
				west=top;
				top=east;
				east=7-west;
			}
		}
		printf("Result is %ld\n",top);
	}
	return 0;
}
