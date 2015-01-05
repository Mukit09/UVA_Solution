#include<stdio.h>
#include<math.h>
#include<string.h>
#define si 100010
char ch[300];

long ara[si],pr[si],cnt=1;

void sieve()
{
	long num=si-5,i,j,root;
	pr[0]=2;
	root=sqrt(num);
	ara[1]=1;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			cnt++;
			pr[cnt]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}

int main()
{
	long i,j,mx,n,l;
	sieve();
	while(gets(ch))
	{
		if(strcmp(ch,"0")==0)
			break;
		l=strlen(ch);
		mx=0;
		for(i=0;i<l;i++)
		{
			n=0;
			for(j=i;j<l;j++)
			{
				n=n*10+ch[j]-48;
				if(n>100000)
					break;
				if(ara[n]==0&&mx<n&&(n%2!=0||n==2))
				{
					mx=n;
				}
			}
		}
		printf("%ld\n",mx);
	}
	return 0;
}
