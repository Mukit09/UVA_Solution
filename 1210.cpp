#include<stdio.h>
#include<math.h>
  
long cnt,pr[100010],n,x[100010],k;

void sieve()
{
	long num=10000,i,j,root;

	k=1;
	pr[k]=2;
	root=sqrt(num);
	for(i=3;i<=num;i+=2)
	{
		if(x[i]==0)
		{
			k++;
			pr[k]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					x[j]=1;
			}
		}
    }
}
  
int main()
{
    long i,m,j;
	sieve();
    while(~scanf("%ld",&n)&&n)
	{
		cnt=0;
		m=n;
		for(i=1;i<=k;i++)
		{
			n=m;
			for(j=i;j<=k;j++)
			{
				n-=pr[j];
				if(n==0)
				{
					cnt++;
					break;
				}
				if(n<0)
					break;
			}
		}
		printf("%ld\n",cnt);
	}
    return 0;
   
}