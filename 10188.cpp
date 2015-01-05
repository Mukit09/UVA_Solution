#include<stdio.h>
#include<string.h>
#define si 1000010

long i,j,k=1,n;
char ind1[si],ind2[si],ins1[si],ins2[si],c;

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		getchar();
		i=j=0;
		while(n)
		{
			c=getchar();
			ins1[i++]=c;
			if(c>=48&&c<=57)
				ind1[j++]=c;
			if(c=='\n')
				n--;
		}
		ins1[i]=0;
		ind1[j]=0;
		scanf("%ld",&n);
		getchar();
		i=j=0;
		while(n)
		{
			c=getchar();
			ins2[i++]=c;
			if(c>=48&&c<=57)
				ind2[j++]=c;
			if(c=='\n')
				n--;
		}
		ins2[i]=0;
		ind2[j]=0;
		if(strcmp(ins1,ins2)==0)
			printf("Run #%ld: Accepted\n",k++);
		else if(strcmp(ind1,ind2)==0)
			printf("Run #%ld: Presentation Error\n",k++);
		else
			printf("Run #%ld: Wrong Answer\n",k++);
	}
	return 0;
}