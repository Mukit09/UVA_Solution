#include<stdio.h>
#include<math.h>
#define si 66000
int ara[si],pr[si],ll=1;

void sieve()
{
	long long num=si-5,i,j,root;
	root=sqrt(num);
	ara[0]=ara[1]=1;
	pr[ll++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
    }
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

int main()
{
	long long i,n,fg,first,cnt,g_cd,l;
	sieve();
	while(~scanf("%lld",&n)&&n)
	{
		fg=0;
		if(n<0)
		{
			fg=1;
			n*=-1;
		}
		l=sqrt(n);
		first=1;
		g_cd=cnt=0;
		for(i=1;pr[i]<=l;i++)
		{
			if(n%pr[i]==0)
			{
				while(n%pr[i]==0)
				{
					n/=pr[i];
					if(first)
						g_cd++;
					else
						cnt++;
				}
				if(g_cd!=cnt&&!first)
					g_cd=gcd(g_cd,cnt);
				cnt=first=0;
			}
		}
		if(n>1)
		{
			cnt=1;
			if(g_cd=cnt)
				g_cd=gcd(g_cd,cnt);
		}
		if(fg&&g_cd%2==0)
		{
			while(!(g_cd%2))
				g_cd/=2;
		}

		printf("%lld\n",g_cd);
	}
	return 0;
}
