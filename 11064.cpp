#include<stdio.h>
#include<math.h>
#define si 50010

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
	int i,n,l,p,cnt,cnt_div;
	double m,j;
	sieve();
	while(~scanf("%d",&n))
	{
		if(n==1||n==2)
		{
			printf("0\n");
			continue;
		}
		l=sqrt(n);
		m=1;
		p=n;
		cnt_div=1;
		for(i=1;pr[i]<=l;i++)
		{
			if(p%pr[i]==0)
			{
				cnt=0;
				j=pr[i];
				m*=((j-1)/j);
				while(p%pr[i]==0)
				{
					cnt++;
					p/=pr[i];
				}
				cnt_div*=(cnt+1);
			}
			if(p==1)
				break;
		}	
		if(p>1)
		{
			cnt=0;
			j=p;
			m*=((j-1)/j);
			i=p;
			while(p%i==0)
			{
				cnt++;
				p/=i;
			}
			cnt_div*=(cnt+1);
		}
		m*=n;
		p=floor(m+0.5);
		p+=cnt_div;
		n-=p;
		printf("%d\n",n+1);
	}
	return 0;
}
