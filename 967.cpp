#include<stdio.h>
#include<math.h>
#define si 1000010

long a[si],res[si],cnt;

long count(long j)
{
	long k=0;
	while(j!=0)
	{
		j/=10;
		k++;
	}
	return k;
}

long cir(long j)
{
	long i,c,cnt;
	c=count(j)-1;
	cnt=c+1;
	c=pow(10,c);
	while(cnt--)
	{
		i=j%10;
		if(i==0||i%2==0||i==5)
			return 0;
		j=j/10;
		j=i*c+j;
		if(a[j])
			return 0;
	}
	return 1;
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
	for(i=113;i<=n;i++)
	{
		if(a[i]==0&&cir(i))
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
	long u,v,fg,re;
	pre_cal();
	while(~scanf("%ld",&u))
	{
		if(u==-1)
			break;
		scanf("%ld",&v);
		if(a[u]==0&&cir(u))
			fg=1;
		else
			fg=0;
		re=res[v]-res[u]+fg;
		if(re==0)
			printf("No Circular Primes.\n");
		else if(re==1)
			printf("%ld Circular Prime.\n",re);
		else
			printf("%ld Circular Primes.\n",re);
	}
	return 0;
}