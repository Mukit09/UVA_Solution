#include<stdio.h>
#include<math.h>
#define si 1000010

int ara[si],pr[si],ll=1;
long long a,b;

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
		ara[i+1]=1;
    }
}

int chk(int x)
{
	long long i,j;
	for(i=1;;i++)
	{
		j=pow(x,i);
		if(j>=a&&j<=b)
			return 1;
		if(j>b)
			return 1;
	}
	return 0;
}

int b_srch()
{
	int l=1,h=ll-1,m,ck;
	while(l<=h)
	{
		m=(l+h)/2;
		ck=chk(pr[m]);
		if(ck)
			h=m-1;
		else
			l=m+1;
	}
	return l;
}

int main()
{
	long long m,i,j,t,x,cnt,p,fg;
	sieve();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		x=b_srch();
		cnt=fg=0;
		for(i=x;;i++)
		{
			m=pow(pr[i],2);
			if(m>b&&fg)
				break;
			j=2;
			while(1)
			{
				m=pow(pr[i],j);
				fg=1;
				if(m>b)
					break;
				if(m>=a&&m<=b)
					cnt++;
				j++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
