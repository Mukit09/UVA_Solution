#include<stdio.h>
#include<math.h>
#define si 10010
#define eps 0.000000001
  
long cnt,n,x[si],k,m,fg,pr[si];
double r,re[si];

void pre_gen()
{
	long n=si-10,i,j,k=0;
	for(i=0;i<=n;i++)
	{
		fg=1;
		m=i*i+i+41;
		for(j=2;j<=sqrt(m);j++)
		{
			if(m%j==0)
			{
				fg=0;
				pr[i]=0;
				break;
			}
		}
		if(fg)
		{
			pr[i]=1;
			re[i]=++k;
		}
		else
			re[i]=k;
	}
}

int main()
{
	pre_gen();
	long u,v;
	double nn;
	while(~scanf("%ld%ld",&u,&v))
	{
		m=u*u+u+41;
		if(pr[u]==1)
			fg=1;
		else
			fg=0;
		nn=v-u+1;
		printf("%.2lf\n",((re[v]-re[u]+fg)*100)/nn+eps);

	}
	return 0;
}
