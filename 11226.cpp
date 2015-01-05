#include<stdio.h>
#include<math.h>
#define si 500010

long pr[si],a[si],len=1,ans[si],smpf[si];

void sieve()
{
	long i,j,n=si-10,root;
	pr[len++]=2;
	root=sqrt(n);
	for(i=3;i<=n;i=i+2)
	{
		if(a[i]==0)
		{
			pr[len++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=n;j+=2*i)
					a[j]=1;
			}
		}
		a[i+1]=1;
    }
}

long sum(long n)
{
	long i,j,m=n,sm=0;
	for(i=1;pr[i]<=sqrt(n);i++)
	{
		if(m%pr[i]==0)
		{
			while(m%pr[i]==0)
			{
				j=m/pr[i];
				if(a[j]==0)
				{
					m/=j;
					sm+=j;
				}
				sm+=pr[i];
				m/=pr[i];
			}
		}
	}
	return sm;
}


void pre_cal()
{
	long n=si-5,i,sm;
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
			smpf[i]=i;
		else
		{
			sm=sum(i);
			smpf[i]=sm;
		}
	}
}


int main()
{
	sieve();
	pre_cal();
	long t,u,v,mx,i,mn,max,cnt,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&u,&v);
		printf("Case #%ld:\n",x++);
		if(u<v)
		{
			mn=u;
			mx=v;
		}
		else
		{
			mn=v;
			mx=u;
		}
		max=cnt=0;
		for(i=mn;i<=mx;i++)
		{
			u=i,cnt=1;
			while(smpf[u]!=u)
			{
				cnt++;
				u=smpf[u];
			}
			if(cnt>max)
				max=cnt;
		}
		printf("%ld\n",max);
	}
	return 0;
}