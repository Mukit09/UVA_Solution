#include<stdio.h>
#include<string.h>
long i,j,l,m,n,sm;

int main()
{
	char ch1[1010],ch2[1010];
	while(~scanf("%s%s",ch1,ch2))
	{
		if(strcmp(ch1,"0")==0&&strcmp(ch2,"0")==0)
			break;
		l=strlen(ch2);
		m=0;
		for(i=0;i<l;i++)
			m=(m*10+(ch2[i]-48))%4;
		if(m==0)
			m=4;
		l=strlen(ch1);
		n=1;
		for(j=0;j<m;j++)
		{
			sm=0;
			for(i=0;i<l;i++)
				sm=(sm*10+(ch1[i]-48))%10;
			n*=sm;
		}
		printf("%ld\n",n%10);
	}
	return 0;
}