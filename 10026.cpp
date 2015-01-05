#include<stdio.h>
#include<algorithm>
using namespace std;

long t,i,fn,tm,n;

struct ss
{
	long ind,tm,fn;
}T[1010];

bool cmp(ss aa,ss bb)
{
	return aa.tm*bb.fn<aa.fn*bb.tm;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&T[i].tm,&T[i].fn);
			T[i].ind=i+1;
		}
		sort(T,T+n,cmp);
		printf("%ld",T[0].ind);
		for(i=1;i<n;i++)
			printf(" %ld",T[i].ind);
		printf("\n");
		if(t)
			printf("\n");
	}
	return 0;
}