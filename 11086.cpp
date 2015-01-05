#include<stdio.h>
#include<math.h>
#define si 1048590

long ans[si],a[si],pr[si],len=1;

void sieve()
{
	long i,j,n=si,root;
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
	long i,j,n=si-10,fg,cnt,k;
	for(i=4;i<=n;i++)
	{
		cnt=0,fg=1;
		if(a[i]==1)
		{
			for(j=1;pr[j]<=sqrt(i);j++)
			{
				if(i%pr[j]==0)
				{
					cnt++;
					k=i/pr[j];
					if(a[k])
					{
						fg=0;
						break;
					}
					else
						cnt++;
					if(cnt>2)
					{
						fg=0;
						break;
					}
				}
			}
		}
		else
			fg=0;
		if(cnt==2&&fg)
			ans[i]=1;
	}
}

int main()
{
	long i,cnt,n,u;
	sieve();
	pre_cal();
	while(~scanf("%ld",&n))
	{
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&u);
			if(ans[u]==1)
				cnt++;
		}
		printf("%ld\n",cnt);
	}
	return 0;
}