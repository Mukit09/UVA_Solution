#include<stdio.h>
#include<math.h>

long re[66000];

long count(long a)
{
	long j,t,c=0;
	for(j=1;j<=sqrt(a);j++)
	{
		if(a%j==0)
		{
			t=a/j;
			if(t==j)
				c++;
			else
				c+=2;
		}
	}
	return c;
}

int main()
{
	long t,i,k=1,a,b,beg,end,mid,c,d;
	
	re[0]=1;
	for(i=1;i<=65000;i++)
	{
		re[i]=re[i-1]+count(re[i-1]);
	}

	k=1;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		beg=0;
		end=65000;
		while(1)
		{
			if(a<re[beg])
			{
				c=beg;
				break;
			}
			mid=(beg+end)/2;
			if(a==re[mid])
			{
				c=mid;
				break;
			}
			else if(a>re[mid])
				beg=mid+1;
			else if(a<re[mid])
				end=mid-1;
		}
		beg=0;
		end=65000;
		while(1)
		{
			if(b>re[end])
			{
				d=end;
				break;
			}
			mid=(beg+end)/2;
			if(b==re[mid])
			{
				d=mid;
				break;
			}
			else if(b>re[mid])
				beg=mid+1;
			else if(b<re[mid])
				end=mid-1;
		}
		printf("Case %ld: %ld\n",k++,d-c+1);
	}
	return 0;
}