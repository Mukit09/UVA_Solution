#include<stdio.h>
#include<math.h>
#define eps 1e-9
#define si 35

int ara[si],pr[si],ll=1,res[910],store[910];

void sieve()
{
	int num=si-5,i,j,root;
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


int main()
{
	long n,k,b,i,sm,a,mx,l,cnt,j;
	double d,x;
	sieve();
	while(~scanf("%ld%ld",&n,&b))
	{
		l=sqrt(b)+1;
		a=b;
		j=1;
		for(i=1;pr[i]<=l&&i<ll;i++)
		{
			if(a%pr[i]==0)
			{
				mx=pr[i];
				cnt=0;
				while(a%pr[i]==0)
				{
					cnt++;
					a/=mx;
				}
			}
			if(a==1)
				break;
		}
		if(a>1)
		{
			mx=a;
			cnt=1;
		}
		k=1;
		sm=0;
		while(1)
		{
			a=pow(mx,k);
			a=n/a;
			if(!a)
				break;
			sm+=a;
			k++;
		}
		sm/=cnt;
		d=0;
		for(i=1;i<=n;i++)
		{
			x=log10(i)/log10(b);
			d+=(x+eps);
		}
		d=floor(d)+1;
		printf("%d %.0lf\n",sm,d);
	}
	return 0;
}