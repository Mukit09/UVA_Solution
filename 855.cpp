#include<stdio.h>
#include<algorithm>

using namespace std;

long s[50005];
long a[50005];

int main()
{
	long i,j,t,st,av,f;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&st,&av,&f);
		for(i=0;i<f;i++)
			scanf("%ld%ld",&s[i],&a[i]);

		sort(s,s+f);
		sort(a,a+f);

		if(f%2==0)
			i=s[f/2-1],j=a[f/2-1];
		else
			i=s[f/2],j=a[f/2];

		printf("\(Street: %ld, Avenue: %ld\)\n",i,j);
	}
	return 0;
}