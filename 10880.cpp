#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

long a[45000];

int main()
{
	long t,i,c,r,m,k=1,p,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&c,&r);
		if(c==r)
		{
			printf("Case #%ld: 0\n",k++);
			continue;
		}
		j=0;
		p=c-r;
		for(i=1;i<=sqrt(p);i++)
		{
			if(p%i==0)
			{
				m=p/i;
				if(c%i==r)
					a[j++]=i;
				if(c%m==r&&i!=m)
					a[j++]=m;
			}
		}
		sort(a,a+j);
		printf("Case #%ld:",k++);
		for(i=0;i<j;i++)
			printf(" %ld",a[i]);
		printf("\n");
	}
	return 0;
}