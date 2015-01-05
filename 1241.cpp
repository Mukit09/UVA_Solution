#include<stdio.h>
#include<math.h>
#define si 5020
long a[si],cnt,i,j,b,l,c,n,m,t;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		l=pow(2,(n+1));
		b=pow(2,n);
		for(i=1;i<=l;i++)
		{
			a[i]=-1;
			if(i<=b)
				a[i]=1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%ld",&c);
			a[c]=0;
		}
		cnt=0;
		j=b+1;
		for(i=1;i<l;i+=2)
		{
			if(a[i]==0&&a[i+1]==0)
				a[j++]=0;
			else if(a[i]==1&&a[i+1]==1)
				a[j++]=1;
			else if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))
			{
				cnt++;
				a[j++]=1;
			}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}