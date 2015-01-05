#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[10000];
	long len,p,q,i;
	while(gets(a))
	{
		if(!strcmp(a,"0"))
			break;
		len=strlen(a);
		if(len%2==0)
		{
			p=(10*(a[0]-48))+(a[1]-48);
			q=(long)sqrt(p);
			p=len/2;
		}
		else
		{
			p=a[0]-48;
			q=(long)sqrt(p);
			p=(len+1)/2;
		}
		printf("%ld",q);
		for(i=1;i<p;i++)
			printf("0");
		printf("\n");
	}
	return 0;
}