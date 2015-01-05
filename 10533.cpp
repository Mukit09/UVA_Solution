#include<stdio.h>
#include<math.h>
#define si 1000010

long a[si],res[si],cnt;

long sm(long j)
{
	long sm=0;
	while(j!=0)
	{
		sm+=j%10;
		j/=10;
	}
	return sm;
}

void pre_cal()
{
	long n=si-10,i,j,root;
	root=sqrt(n);
	a[1]=1;
	for(i=3;i<=n;i=i+2)
	{
		if(a[i]==0)
		{
			if(i<=root)
			{
				for(j=i*i;j<=n;j+=2*i)
					a[j]=1;
			}
		}
		if((i+1)%2==0)
			a[i+1]=1;
    }
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0&&a[sm(i)]==0)
		{
			cnt++;
			res[i]=cnt;
		}
		else
			res[i]=cnt;
	}
}

int main()
{
	long t,u,v,x=1,fg;
	pre_cal();
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&u,&v);
		if(a[u]==0&&a[sm(u)]==0)
			fg=1;
		else
			fg=0;
		printf("%ld\n",res[v]-res[u]+fg);
	}
	return 0;
}