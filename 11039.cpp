#include<stdio.h>
#include<algorithm>

using namespace std;

long ar[10000000],ab[10000000];

int main()
{
	long i,t,n,j,k,a,b,c,flag;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		j=k=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a);
			if(a>0)
				ab[j++]=a;
			else
			{
				a=-a;
				ar[k++]=a;
			}
		}
		sort(ab,ab+j);
		sort(ar,ar+k);

		flag=a=b=c=0;
		if(ab[0]<ar[0])
		{
			while(1)
			{
				if(ar[a]>ab[b]&&!flag)
				{
					c++;
					b++;
					flag=1;
				}
				else if(ar[a]<ab[b]&&flag)
				{
					c++;
					a++;
					flag=0;
				}
				else if(flag)
					b++;
				else
					a++;
				if(b>=j||a>=k)
					break;
			}
		}
		else
		{
			while(1)
			{
				if(ar[a]<ab[b]&&!flag)
				{
					c++;
					a++;
					flag=1;
				}
				else if(ar[a]>ab[b]&&flag)
				{
					c++;
					b++;
					flag=0;
				}
				else if(flag)
					a++;

				else
					b++;
				if(a>=k||b>=j)
					break;
			}
		}
		printf("%ld\n",c+1);
	}
	return 0;
}