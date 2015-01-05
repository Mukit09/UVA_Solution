#include<stdio.h>

int main()
{
	long t,k=1,i,a,b,j,n,sum,flag;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		printf("case #%ld\n",k++);
		j=a;
		flag=0;
		while(j<=b)
		{
			i=10;
			n=j*j;
			sum=n%10;
			n/=10;
			while(1)
			{
				if(n+sum==j&&sum!=0)
				{
					printf("%ld\n",j);
					flag=1;
					break;
				}
				if(n==0)
					break;
				sum=(n%10)*i+sum;
				n/=10;
				i*=10;
			}
			j++;
		}
		if(!flag)
			printf("no kaprekar numbers\n");
		if(t)
			printf("\n");
	}
	return 0;
}