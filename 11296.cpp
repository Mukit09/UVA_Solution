#include<stdio.h>

double a[1000010];

int main()
{
	long n,i,j;
	double k;
	a[0]=1;
	a[1]=1;
	a[2]=3;
	a[3]=3;
	for(i=4,j=5,k=3;i<1000010;i+=2,j+=2,k++)
	{
		a[i]=a[i-2]+k;
		a[j]=a[j-2]+k;
	}
	while(scanf("%ld",&n)==1)
	{
		printf("%.0lf\n",a[n]);
	}
	return 0;
}