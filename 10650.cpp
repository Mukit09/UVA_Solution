#include<stdio.h>
#include<math.h>
#define si 32020

long ans[si],a[si],pr[si],len=1;

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

int main()
{
	sieve();
	long u,v,low,high,mid,i,ind,dif,fg,k,j,mn,mx;
	while(~scanf("%ld%ld",&u,&v)&&(u||v))
	{
		if(u>v)
		{
			mn=v;
			mx=u;
		}
		else
		{
			mn=u;
			mx=v;
		}
		for(i=1;pr[i]<=mx;i++)
		{
			if((pr[i+2]-pr[i+1]==pr[i+1]-pr[i])&&pr[i+2]<=mx&&pr[i]>=mn)
			{
				fg=1;
				dif=pr[i+1]-pr[i];
				if(pr[i]-pr[i-1]==dif)
					continue;
				k=0;
				ans[k++]=pr[i];
				ans[k++]=pr[i+1];
				ans[k++]=pr[i+2];
				i+=2;
				while(pr[i+1]-pr[i]==dif)
				{
					ans[k++]=pr[i+1];
					if(pr[i+1]>mx)
						fg=0;
					i++;
				}
				i--;
				if(fg)
				{
					printf("%ld",ans[0]);
					for(j=1;j<k;j++)
						printf(" %ld",ans[j]);
					printf("\n");
				}
			}

		}
	}
	return 0;
}