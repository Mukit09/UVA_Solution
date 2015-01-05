#include<stdio.h>
#include<math.h>
#define si 1000010

long pr[si],a[si],len=1,ind_l,ind_u,ans[si];

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
	long n=si-5,sm=0,k,cnt,i,j,x;
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			sm++;
			ans[i]=sm;
		}
		else
		{
			cnt=0;
			k=i;
			for(j=1;pr[j]<=sqrt(i);j++)
			{
				if(k%pr[j]==0)
				{
					while(k%pr[j]==0)
					{
						x=k/pr[j];
						if(a[x]==0)
						{
							k/=pr[j];
							k/=x;
							cnt+=2;
						}
						else
						{
							cnt++;
							k/=pr[j];
						}
					}
					if(k==1)
						break;
				}
			}
			sm+=cnt;
			ans[i]=sm;
		}
	}
}


int main()
{
	sieve();
	pre_cal();
	long n;
	while(~scanf("%ld",&n))
	{
		printf("%ld\n",ans[n]);
	}
	return 0;
}