#include<stdio.h>
#include<math.h>
#define si 1000010

long pr[si],a[si],len=1,mu[si],M[si];

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

void pre_cal()
{
	long n=si-5,sm=0,k,cnt,cnt1,i,j,x,fg;
	mu[1]=M[1]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
			mu[i]=-1;
		else
		{
			k=i,cnt=0;
			for(j=1;pr[j]<=sqrt(i);j++)
			{
				fg=1;
				if(k%pr[j]==0)
				{
					cnt1=0;
					x=k/pr[j];
					if(a[x]==0)
					{
						cnt++;
						while(k%x==0)
						{
							k/=x;
							cnt1++;
							if(cnt1>1)
							{
								fg=0;
								mu[i]=0;
								break;
							}
						}
						if(fg==0)
							break;
					}
					cnt1=0;
					cnt++;
					while(k%pr[j]==0)
					{
						k/=pr[j];
						cnt1++;
						if(cnt1>1)
						{
							fg=0;
							mu[i]=0;
							break;
						}
					}
					if(fg==0)
						break;
					if(k==1)
						break;
				}
			}
			if(cnt%2==0&&fg)
				mu[i]=1;
			else if(cnt%2!=0&&fg)
				mu[i]=-1;
		}
		M[i]=M[i-1]+mu[i];
	}
}

int main()
{
	sieve();
	pre_cal();
	long n;
	while(~scanf("%ld",&n)&&n)
	{
		printf("%8ld%8ld%8ld\n",n,mu[n],M[n]);
	}
	return 0;
}