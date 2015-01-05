#include<stdio.h>
#include<string.h>

long a[100001];
char ch[10001][80];

int main()
{
	long i=1,j,t;
	char c;
	scanf("%ld",&t);
	while(t--)
	{
		while(1)
		{
			scanf("%ld%c",&a[i],&c);
			if(c=='\n')
				break;
			i++;
		}
		for(j=1;j<=i;j++)
			scanf("%s",ch[a[j]]);

		for(j=1;j<=i;j++)
			puts(ch[j]);
		
		if(t)
			printf("\n");
		i=1;
	}
	return 0;
}

