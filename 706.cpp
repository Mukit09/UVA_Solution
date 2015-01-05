#include<stdio.h>
#include<string.h>
long i,j,k,n;
char s[20];

void Top()
{
	for(i=0;s[i];i++)
	{
		if(i)
			printf(" ");
		if(s[i]=='1'||s[i]=='4')
		{
			for(k=0;k<n+2;k++)
				printf(" ");
		}
		else
		{
			printf(" ");
			for(k=0;k<n;k++)
				printf("-");
			printf(" ");
		}
	}
	printf("\n");
}

void Mid_up()
{
	for(i=0;s[i];i++)
	{
		if(i)
			printf(" ");
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='7')
		{
			for(k=0;k<=n;k++)
				printf(" ");
			printf("|");
		}
		else if(s[i]=='4'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			printf("|");
			for(k=0;k<n;k++)
				printf(" ");
			printf("|");
		}
		else
		{
			printf("|");
			for(k=0;k<=n;k++)
				printf(" ");
		}
	}
	printf("\n");
}

void Mid()
{
	for(i=0;s[i];i++)
	{
		if(i)
			printf(" ");
		if(s[i]=='1'||s[i]=='7'||s[i]=='0')
		{
			for(k=0;k<n+2;k++)
				printf(" ");
		}
		else
		{
			printf(" ");
			for(k=0;k<n;k++)
				printf("-");
			printf(" ");
		}
	}
	printf("\n");
}

void Mid_down()
{
	for(i=0;s[i];i++)
	{
		if(i)
			printf(" ");
		if(s[i]=='2')
		{
			printf("|");
			for(k=0;k<=n;k++)
				printf(" ");
		}
		else if(s[i]=='6'||s[i]=='8'||s[i]=='0')
		{
			printf("|");
			for(k=0;k<n;k++)
				printf(" ");
			printf("|");
		}
		else
		{
			for(k=0;k<=n;k++)
				printf(" ");
			printf("|");
		}
	}
	printf("\n");
}

void Bottom()
{
	for(i=0;s[i];i++)
	{
		if(i)
			printf(" ");
		if(s[i]=='1'||s[i]=='7'||s[i]=='4')
		{
			for(k=0;k<n+2;k++)
				printf(" ");
		}
		else
		{
			printf(" ");
			for(k=0;k<n;k++)
				printf("-");
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	while(scanf("%ld%s",&n,s) && (n||strcmp(s,"0")))
	{
		Top();
		for(j=0;j<n;j++)
			Mid_up();
		Mid();
		for(j=0;j<n;j++)
			Mid_down();
		Bottom();
		printf("\n");
	}
	return 0;
}