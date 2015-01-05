#include<stdio.h>
#include<math.h>
#define si 40010

int a[si],pr[si],ll=1;
void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	a[1]=1;
	pr[ll++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(a[i]==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					a[j]=1;
			}
		}
    }
}

int main()
{
	int i,n,l,p;
	double m,j;
	sieve();
	while(~scanf("%d",&n)&&n)
	{
		if(n==1||n==2)
		{
			printf("%d\n",n-1);
			continue;
		}
		l=sqrt(n);
		m=1;
		p=n;
		for(i=1;pr[i]<=l;i++)
		{
			if(p%pr[i]==0)
			{
				j=pr[i];
				m*=((j-1)/j);
				while(p%pr[i]==0)
					p/=pr[i];
			}
		}	
		if(p>1)
		{
			j=p;
			m*=((j-1)/j);
		}
		m*=n;
		printf("%.0lf\n",m);
	}
	return 0;
}
