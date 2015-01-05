#include<stdio.h>
#include<string.h>

long i,a[301],t;

char ch1[10000],ch2[10000];
char ch[10000];

int main()
{
	scanf("%ld",&t);
	getchar();
	getchar();
	while(t--)
	{
		gets(ch1);
		gets(ch2);
		for(i=0;i<256;i++)
			a[i]=i;
		for(i=0;ch1[i];i++)
			a[ch1[i]]=ch2[i];
		
		puts(ch2);
		puts(ch1);

		while(gets(ch))
		{
			if(ch[0]==0)
				break;
			for(i=0;ch[i];i++)
				printf("%c",a[ch[i]]);
			printf("\n");
		}
		if(t)
			printf("\n");
	}
	return 0;
}